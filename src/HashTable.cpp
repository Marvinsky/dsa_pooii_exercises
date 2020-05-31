#include "types.h"
#include "LinkedList.cpp"

class HashTable {
    LinkedList** data;
    int length;
  public:
    HashTable(int size) {
      this->length = size;
      this->data = new LinkedList*[size];
      for (int i = 0; i < size; i++) {
        this->data[i] = new LinkedList();
      }
    }

    void insert(string value) {
      int index = abs(hashFunction(value))%this->length;
      this->data[index]->insert(value);
    }

    bool search(string value) {
      int index = abs(hashFunction(value))%this->length;
      return this->data[index]->search(value);
    }

    bool deleteValue(string value) {
      int index = abs(hashFunction(value))%this->length;
      return this->data[index]->deleteValue(value);
    }

  private:
    int hashFunction(string value) {
      int hash = 7;
      for (int i = 0; i < value.length(); i++) {
        hash = hash * 31 + value[i];
      }
      return hash;
    }

    int jenkins_hash(string value) {
      int hash = 0;
      for (int i = 0; i < value.length(); i++) {
        hash += (value[i] & 0xFF);
        hash += (hash << 10);
        hash ^= (hash >> 6);
      }
      hash += (hash << 3);
      hash ^= (hash >> 11);
      hash += (hash << 15);
      return hash;
    }
};