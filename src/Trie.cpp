#include "TrieNode.cpp"

class Trie {
    TrieNode* root;
  public:
    Trie() {
      this->root = new TrieNode();
    }

    void insert(string value) {
      TrieNode* n = root;//"n" represents some prefix in "value"
      for (int i = 0; i < value.length(); i++) {
        if (!n->haveRecord(value[i])) {
          n->addRecord(value[i], new TrieNode());
        }
        n = n->followChar(value[i]);
      }
      n->setIsWord(true);
    }

    bool search(string value) {
      TrieNode* n = root;
      for (int i = 0; i < value.length(); i++) {
        if (!n->haveRecord(value[i])) {
          return false;
        }
        n = n->followChar(value[i]);
      }
      return n->getIsWord();
    }

    bool deleteValue(string value) {
      TrieNode* n = root;
      TrieNode** path = new TrieNode*[value.length()];
      int pathLength = 0;
      for (int i = 0; i < value.length(); i++) {
        if (!n->haveRecord(value[i])) {
          //value is not in this tree
          return false;
        }
        n = n->followChar(value[i]);
        path[pathLength] = n;
        pathLength++;
      }
      n->setIsWord(false);
      //delete nodes that are no longer needed
      int inputIndex = value.length() - 1;//from the end to 0
      for (int i = pathLength - 2; i >= 0; i--) {
        if (n->haveNoRecord() && (!n->getIsWord())) {
          //node can be deleted
          n = path[i];//i is index of parent node in path
          n->deleteRecord(value[inputIndex]);
          inputIndex--;
        } else {
          //node can not be deleted
          break;
        }
      }
      return true;
    }

    string findLCP(string dict[]) {
      TrieNode* n = root;
      string lcp;
      while (n && !n->getIsWord() && (n->getTable().size() == 1)) {
        auto it = n->getTable().begin();
        lcp += it->first;
        n = it->second;
      }
      return lcp;
    }
};