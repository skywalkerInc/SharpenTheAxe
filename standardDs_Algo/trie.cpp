#include <bits/stdc++.h>
using namespace std;

struct Node {
    bool isLeaf;
    vector<Node*> chars;
    Node(): isLeaf(false), chars{vector<Node*>(26, nullptr)} {}
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node *iter = root;
        for (auto &ch: word) {
            int pos = ch - 'a';
            if (!iter->chars[pos]) {
                iter->chars[pos] = new Node();
            }
            iter = iter->chars[pos];
        }
        iter->isLeaf = true;
    }

    bool search(string word) {
        Node *iter = root;
        for (int i=0; i<word.size() && iter; ++i) {
            int pos = word[i] - 'a';
            iter = iter->chars[pos];
        }
        if (iter && iter->isLeaf) return true;
        return false;
    }
};

int main() {
    Trie trie = Trie();
    string word = "kawal";
    trie.insert(word);
    cout << trie.search("kawal") << endl;
    cout << trie.search("ka") << endl;
}