#include "types.h"

class BinarySearchTreeNode {
  private:  
    int value;
    BinarySearchTreeNode *left;
    BinarySearchTreeNode *right;
  public:
    BinarySearchTreeNode(int value) {
      this->value = value;
      this->left = nullptr;
      this->right = nullptr;
    }

    int getValue() {
      return this->value;
    }

    void setValue(int value) {
      this->value = value;
    }

    BinarySearchTreeNode* getLeft() {
      return this->left;
    }

    void setLeft(BinarySearchTreeNode* left) {
      this->left = left;
    }

    BinarySearchTreeNode* getRight() {
      return this->right;
    }

    void setRight(BinarySearchTreeNode* right) {
      this->right = right;
    }  
};