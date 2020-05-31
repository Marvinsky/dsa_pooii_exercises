#include "types.h"

class TrieNode {
    map<char, TrieNode*> table;
    bool isWord;
  public:
    TrieNode() {
      isWord = false;
    }

    bool haveRecord(char c){
      map<char, TrieNode*>::iterator iter;
      for (iter = table.begin(); iter != table.end(); iter++) {
        if (iter->first == c) {
          return true;
        }
      }
      return false;
    }

    bool haveNoRecord() {
      return this->table.size() > 0 ? false : true;
    }

    TrieNode* followChar(char c) {
      map<char, TrieNode*>::iterator iter;
      for (iter = table.begin(); iter != table.end(); iter++) {
        if (iter->first == c) {
          return iter->second;
        }
      }
      return nullptr;
    }

    void addRecord(char c, TrieNode* n) {
      this->table[c] = n;
    }

    void deleteRecord(char c) {
      map<char, TrieNode*>::iterator iter = table.begin();
      for (; iter != table.end(); iter++) {
        if (iter->first == c) {
          table.erase(iter);
          break;
        }
      }
    }

    bool getIsWord() {
      return this->isWord;
    }

    void setIsWord(bool isWord) {
      this->isWord = isWord;
    }

    map<char, TrieNode*> getTable() {
      return this->table;
    }

    void setTable(map<char, TrieNode*> table) {
      this->table = table;
    }
};