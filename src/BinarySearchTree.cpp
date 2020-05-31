#include "BinarySearchTreeNode.cpp"

class BinarySearchTree {
    BinarySearchTreeNode* root;
  public:
    BinarySearchTree() {
      root = nullptr;
    }

    BinarySearchTreeNode* getRoot(){
      return this->root;
    }

    void insert(int value) {
      if (root == nullptr) {
        root = new BinarySearchTreeNode(value);
        return;
      }

      BinarySearchTreeNode* parent = root;
      BinarySearchTreeNode* current = root;

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
        parent->setRight(new BinarySearchTreeNode(value));
      } else {
        parent->setLeft(new BinarySearchTreeNode(value));
      }
    }

    bool search(int value) {
      BinarySearchTreeNode* current = this->root;
      while (current != nullptr) {
        if (current->getValue() > value) {
          current = current->getLeft();
        } else if (current->getValue() < value) {
          current = current->getRight();
        } else {
          return true;
        }
      }
      return false;
    }

    bool deleteValue(int value) {
      if (this->root == nullptr) {// In case tree is empty
        return false;
      }
      BinarySearchTreeNode* current = this->root;
      BinarySearchTreeNode* parent = nullptr;

      while (current != nullptr) {
        parent = current;
        if (current->getValue() < value) {
          current = current->getRight();
        } else if (current->getValue() > value) {
          current = current->getLeft();
        }
        if (current == nullptr) {
          return false;// value is not in the tree
        }
      }

      // now we have in current the node that we want to delete
      //case 1: current is a leaf
      if ((current->getLeft() == nullptr) && (current->getRight() == nullptr)) {
        if (current == this->root) {
          this->root = nullptr;
        } else if (parent->getValue() < current->getValue()) {
          parent->setRight(nullptr);
        } else {
          parent->setLeft(nullptr);
        }
        return true;
      }

      //case 2: Current have one child
      if (current->getLeft() == nullptr) {
        if (current == this->root) {
          this->root = current->getRight();
        } else if (parent->getValue() < current->getValue()) {
          parent->setRight(current->getRight());
        } else {
          parent->setLeft(current->getRight());
        }
        return true;
      } else if (current->getRight() == nullptr) {
        if (current == this->root) {
          this->root = current->getLeft();
        } else if (parent->getValue() < current->getValue()) {
          parent->setRight(current->getLeft());
        } else {
          parent->setLeft(current->getLeft());
        }
        return true;
      }

      //case 3: Current have left and right child
      if ((current->getRight() != nullptr) && (current->getLeft() != nullptr)) {
        BinarySearchTreeNode* successor = getBiggestNodeFromLeftSubtree(current);
        successor->setLeft(current->getLeft());
        successor->setRight(current->getRight());
        if (current == this->root) {
          this->root = successor;
        } else if (parent->getValue() < current->getValue()) {
          parent->setRight(successor);
        } else {
          parent->setLeft(successor);
        }
        return true;
      }
    }

    void print() {
      int length = 1;
      BinarySearchTreeNode** nodes = new BinarySearchTreeNode*[length];
      nodes[0] = this->root;
      if (this->root == nullptr) {
        return;
      }
      int height = max(getHeight(this->root->getLeft()), getHeight(this->root->getRight()));
      cout<<"Height = "<<height<<endl;

      while (haveNodesToPrint(nodes, length)) {
        int offset = (int)pow(2, height + 1);
        for (int i = 0; i < length; i++) {
          printSpace(offset);//offset before every number
          if (nodes[i] != nullptr) {
            cout<<nodes[i]->getValue();
          } else {
            cout<<" ";
          }
          printSpace(offset - 2);//minus 2 because we expect the number to have length
        }
        //print the spaces
        for (int i = 0; i <= height; i++) {
          cout<<endl;
        }
        //prepare for printing next line
        BinarySearchTreeNode** newNodes = new BinarySearchTreeNode*[length*2];
        int index = 0;
        for (int j = 0; j < length; j++) {
          if (nodes[j] != nullptr) {
            newNodes[index] = nodes[j]->getLeft();
            index++;
            newNodes[index] = nodes[j]->getRight();
            index++;
          } else {
            //even if it is nullptr you need to print spaces
            newNodes[index] = nullptr;
            index++;
            newNodes[index] = nullptr;
            index++;
          }
        }
        length = length*2;
        nodes = newNodes;
        height--;
      }
    }

    void postorder(BinarySearchTreeNode* node) {
      if (node == nullptr) {
        return;
      }
      postorder(node->getLeft());
      postorder(node->getRight());
      cout<<node->getValue()<<" ";
    }

    void inorder(BinarySearchTreeNode* node) {
      if (node == nullptr) {
        return;
      }
      inorder(node->getLeft());
      cout<<node->getValue()<<" ";
      inorder(node->getRight());
    }

    void preorder(BinarySearchTreeNode* node) {
      if (node == nullptr) {
        return;
      }
      cout<<node->getValue()<<" ";
      preorder(node->getLeft());
      preorder(node->getRight());
    }
 
  private:
    int getHeight(BinarySearchTreeNode* current) {
      if ((current->getLeft() != nullptr) && (current->getRight() != nullptr)) {
        return 1 + max(getHeight(current->getLeft()), getHeight(current->getRight()));
      } else if (current->getLeft() != nullptr) {
        return 1 + getHeight(current->getLeft());
      } else if (current->getRight() != nullptr) {
        return 1 + getHeight(current->getRight());
      } else {
        return 1;
      }
    }

    BinarySearchTreeNode* getBiggestNodeFromLeftSubtree(BinarySearchTreeNode* start) {
      BinarySearchTreeNode* parent = start->getLeft();//in left subtree
      BinarySearchTreeNode* rightChild = parent->getRight();//Represent the most right node
      if (rightChild == nullptr) {//in case left subtree of start have no right child
        start->setLeft(parent->getLeft());
        return parent;
      }
      while (rightChild->getRight() != nullptr) {
        parent = rightChild;
        rightChild = rightChild->getRight();
      }
      //in rightChild is the most right (biggest) node
      // if biggest node have leftChild it will be set as right child of parent
      // if leftChild is null, the right child of parent will be also null
      parent->setRight(rightChild->getLeft());
      return rightChild;
    }

    bool haveNodesToPrint(BinarySearchTreeNode** nodes, int n) {

    }

    void printSpace(int n) {

    }
};

