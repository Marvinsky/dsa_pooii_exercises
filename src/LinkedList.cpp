#include "types.h"

class Node {
    string value;
    Node* next;
  public:
    Node(string value, Node* next) {
      this->value = value;
      this->next = next;
    }

    string getValue() {
      return value;
    }

    void setValue(string value) {
      this->value = value;
    }

    Node* getNext() {
      return this->next;
    }

    void setNext(Node* next) {
      this->next = next;
    }
};

class LinkedList {
    Node* head;
  public:
    LinkedList() {
      this->head = nullptr;
    }

    void insert(string value) {
      this->head = new Node(value, this->head);
    }

    bool search(string value) {
      Node* n = this->head;
      while(n != nullptr) {
        if (n->getValue() == value) {
          return true;
        }
        n = n->getNext();
      }
      return false;
    }

    bool deleteValue(string value) {
      if (this->head == nullptr) {
        return false;
      } else if (this->head->getValue() == value) {
        //delete head
        this->head = this->head->getNext();
        return true;
      }

      Node* previous = this->head;
      Node* current = this->head->getNext();
      while (current != nullptr) {
        if (current->getValue() == value) {
          previous->setNext(current->getNext());
          return true;
        }
        previous = current;
        current = current->getNext();
      }
      return false;
    }

    void print() {
      Node* n = this->head;
      while (n != nullptr) {
        cout<<n->getValue()<<", ";
        n = n->getNext();
      }
    }
};