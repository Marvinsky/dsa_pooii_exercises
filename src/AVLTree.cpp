#include "AVLNode.cpp"

class AVLTree {
    AVLNode* root;
  public:
    AVLTree() {
      this->root = nullptr;
    }

    AVLNode* getRoot(){
      return this->root;
    }

    void insert(int value) {
      if (this->root == nullptr) {
        this->root = new AVLNode(value, nullptr);
        return;
      }
      AVLNode* current = this->root;
      while(true) {
        if (current->getValue() < value) {
          if (current->getRight() != nullptr) {
            current = current->getRight();
          } else {
            current->setRight(new AVLNode(value, current));
            break;
          }
        } else if (current->getValue() > value) {
          if (current->getLeft() != nullptr) {
            current = current->getLeft();
          } else {
            current->setLeft(new AVLNode(value, current));
            break;
          }
        } else {
          //the value you are inserting is already in tree
          return;
        }
      }


      /*
      AVLNode* parent = root;
      AVLNode* current = root;
      while (current != nullptr) {
        parent = current;
        if (current->getValue() < value) {
          current = current->getRight();
        } else if (current->getValue() > value) {
          current = current->getLeft();
        } else {
          //the value you are inserting is already in the tree
          return;
        }
      }

      if (parent->getValue() < value) {
        parent->setRight(new AVLNode(value, current));
      } else {
        parent->setLeft(new AVLNode(value, current));
      }*/

      //after insertion we rebalance
      rebalance(current);
    }

    bool search(int value) {
      AVLNode* current = this->root;
      while (current != nullptr) {
        if (current->getValue() < value) {
          current = current->getRight();
        } else if (current->getValue() > value) {
          current = current->getLeft();
        } else {
          return true;
        }
      }
      return false;
    }

    bool deleteValue(int value) {
      AVLNode* current = this->root;
      while (current != nullptr) {
        if (current->getValue() < value) {
          current = current->getRight();
        } else if (current->getValue() > value) {
          current = current->getLeft();
        } else {
          deleteNode(current);
          return true;
        }
      }
      return false;//value is not in the tree
    }

    void print() {

    }

    void postorder(AVLNode* node) {
      if (node == nullptr) {
        return;
      }
      postorder(node->getLeft());
      postorder(node->getRight());
      cout<<node->getValue()<<" ";
    }

    void inorder(AVLNode* node) {
      if (node == nullptr) {
        return;
      }
      inorder(node->getLeft());
      cout<<node->getValue()<<" ";
      inorder(node->getRight());
    }

    void preorder(AVLNode* node) {
      if (node == nullptr) {
        return;
      }
      cout<<node->getValue()<<" ";
      preorder(node->getLeft());
      preorder(node->getRight());
    }    
  private:
    void deleteNode(AVLNode* node) {
      //case 1
      // node is leaf
      if (node->getLeft() == nullptr &&node->getRight() == nullptr) {
        if (node != this->root) {
          AVLNode* parent = node->getParent();
          if (parent->getValue() < node->getValue()) {
            parent->setRight(nullptr);
          } else {
            parent->setLeft(nullptr);
          }
          rebalance(parent);
        } else {
          //if node have no parents it is root
          this->root = nullptr;
        }
        return;
      }

      //case 2
      // node have no child
      if (node->getLeft() == nullptr) {
        if (node != this->root) {
          AVLNode* parent = node->getParent();
          if (parent->getValue() < node->getValue()) {
            parent->setRight(node->getRight());
          } else {
            parent->setLeft(node->getRight());
          }
        } else {
          //if node have no parents it is root
          node->getRight()->setParent(nullptr);
          this->root = node->getRight();
        }
        rebalance(node->getRight());
        return;
      } else if (node->getRight() == nullptr) {
        AVLNode* parent = node->getParent();
        if (node == this->root) {
          node->getLeft()->setParent(nullptr);
          this->root = node->getLeft();
        } else if (parent->getValue() < node->getValue()) {
          parent->setRight(node->getLeft());
        } else {
          parent->setLeft(node->getLeft());
        }
        rebalance(node->getLeft());
        return;
      }

      //case 3
      // node have left and right child
      if (node->getLeft() != nullptr && node->getRight() != nullptr) {
        AVLNode* successor = getBiggestNodeFromLeftSubtree(node);
        successor->setLeft(node->getLeft());
        successor->setRight(node->getRight());

        AVLNode* parent = node->getParent();
        if (node != this->root) {
          if (parent->getValue() < node->getValue()) {
            parent->setRight(successor);
          } else {
            parent->setLeft(successor);
          }
        } else {
          //if node have no parent it is root
          successor->setParent(nullptr);
          this->root = successor;
        }
        rebalance(successor);
      } 
    }

    AVLNode* getBiggestNodeFromLeftSubtree(AVLNode* node) {
      AVLNode* result = node->getLeft();
      if (result->getRight() == nullptr){
        //no right child
        node->setLeft(result->getLeft());
        return result;
      }
      while (result->getRight() != nullptr) {
        result = result->getRight();
      }
      result->getParent()->setRight(result->getLeft());
      return result;
    }

    void rebalance(AVLNode* node) {
      int balance = node->getBalance();
      if (balance == -2) {
        //height of left subtree is bigger by 2
        if (node->getLeft()->getBalance() == 1) {
          node = LR(node);
        } else {
          node = RR(node);
        }
      } else if (balance == 2) {
        //height of right subtree is bigger by 2
        if (node->getRight()->getBalance() == -1) {
          node = RL(node);
        } else {
          node = LL(node);
        }
      }
      if (node != this->root) {
        rebalance(node->getParent());
      }
    }

    AVLNode* LL(AVLNode* node) {
      AVLNode* right = node->getRight();
      AVLNode* parent = node->getParent();
      node->setRight(right->getLeft());

      right->setLeft(node);

      if (node != this->root) {
        if (parent->getValue() < right->getValue()) {
          parent->setRight(right);
        } else {
          parent->setLeft(right);
        }
      } else {
        right->setParent(nullptr);
        this->root = right;
      }
      return right;
    }

    AVLNode* RR(AVLNode* node) {
      AVLNode* left = node->getLeft();
      AVLNode* parent = left->getParent();
      node->setLeft(left->getRight());

      left->setRight(node);
      if (node != this->root) {
        if (parent->getValue() < node->getValue()) {
          parent->setRight(left);
        } else {
          parent->setLeft(left);
        }
      } else {
        left->setParent(nullptr);
        this->root = left;
      }
      return left;
    }

    AVLNode* RL(AVLNode* node) {
      RR(node->getRight());
      return LL(node);
    }

    AVLNode* LR(AVLNode* node) {
      LL(node->getLeft());
      return RR(node);
    }
};
