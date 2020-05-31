#include "types.h"

class AVLNode {
  int value;
  AVLNode* left;
  AVLNode* right;
  AVLNode* parent;
  public:
    AVLNode(int value, AVLNode* parent) {
      this->value = value;
      this->left = nullptr;
      this->right = nullptr;
      this->parent = parent;
    }

    void setAsParent(AVLNode* child) {
      if (child != nullptr) {
        child->setParent(this);
      }
    }

    int getBalance() {
      if (this->left != nullptr && this->right != nullptr) {
        return this->right->getHeight() - this->left->getHeight();
      } else if (this->left != nullptr) {
        int result = 0 - this->left->getHeight();
        return result;
      } else if (this->right != nullptr) {
        return this->right->getHeight();
      } else {
        return 0;
      }
    }

    int getHeight() {
      if (this->left != nullptr && this->right != nullptr) {
        return 1 + max(this->left->getHeight(), this->right->getHeight());
      } else if (this->left != nullptr) {
        return 1 + this->left->getHeight();
      } else if (this->right != nullptr) {
        return 1 + this->right->getHeight();
      } else {
        return 1;
      }
    }

    AVLNode* getParent() {
      return this->parent;
    }

    void setParent(AVLNode* parent) {
      this->parent = parent;
    }

    int getValue() {
      return this->value;
    }

    void setValue(int value) {
      this->value = value;
    }

    AVLNode* getLeft() {
      return this->left;
    }

    void setLeft(AVLNode* left) {
      this->setAsParent(left);
      this->left = left;
    }

    AVLNode* getRight() {
      return this->right;
    }

    void setRight(AVLNode* right) {
      this->setAsParent(right);
      this->right = right;
    }
};