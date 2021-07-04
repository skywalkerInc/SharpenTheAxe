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

    void getAllWord(Node* root, vector<string>& out, string word) {
        if (root->isLeaf) {
            out.push_back(word);
        }
        
        for (int i=0; i<26; i++) {
            if (root->chars[i]) {
                word.push_back(char('a' + i));
                getAllWord(root->chars[i], out, word);
                word.pop_back();
            }
        }
    }
    
    vector<string> getWordByPrefix(string prefix) {
        Node* iter = root;
        vector<string> out;
        for(int i=0; i<prefix.size() && iter; i++) {
            int pos = prefix[i] - 'a';
            iter = iter->chars[pos];
            cout << char('a' + i) << ", ";
        }
        cout << endl;
        if (iter) getAllWord(iter, out, prefix);
        return out;
    }

};


class TrieNode {
public: 
    bool isLeaf;
    vector<TrieNode*> chars;
    TrieNode(): isLeaf(false), chars{vector<TrieNode*>(26, nullptr)} {}
};
    
    
class TrieTemp {
    TrieNode* root;
public:
    TrieTemp(vector<string>& words) {
        root = new TrieNode();
        for (auto &word: words) {
            insert(word);
        }
    }
    
    void insert(string word) {
        TrieNode* iter = root;
        for (auto &ch: word) {
            int pos = ch - 'a';
            if (!iter->chars[pos]) {
                iter->chars[pos] = new TrieNode();
            }
            iter = iter->chars[pos];
        }
        iter->isLeaf = true;
    }
    
    
    void getAllWord(TrieNode* root, vector<string>& out, string word) {
        if (root->isLeaf) {
            out.push_back(word);
        }
        
        for (int i=0; i<26; i++) {
            if (root->chars[i]) {
                word.push_back(char('a' + i));
                getAllWord(root->chars[i], out, word);
                word.pop_back();
            }
        }
    }
    
    vector<string> getWordByPrefix(string prefix) {
        TrieNode* iter = root;
        vector<string> out;
        for(int i=0; i<prefix.size() && iter; i++) {
            int pos = prefix[i] - 'a';
            iter = iter->chars[pos];
        }
        if (iter) getAllWord(iter, out, prefix);
        return out;
    }
};

int main() {
    // Trie trie = Trie();
    // string word = "kawal";
    // trie.insert(word);
    // trie.insert("kawaljeet");
    // trie.insert("kumar");
    // trie.insert("kanwaljeet");
    // trie.insert("kawalmeet");
    // cout << trie.search("kawal") << endl;
    // cout << trie.search("ka") << endl;
    // vector<string> res = trie.getWordByPrefix("");
    // for (auto &word: res) {
    //     cout << word << endl;
    // }

    vector<string> words = {"kawal", "kawaljeet", "kumar", "kamaljeet", "kawalmeet"};
    TrieTemp trieTemp = TrieTemp(words);
    vector<string> res = trieTemp.getWordByPrefix("");
    for (auto &word: res) {
        cout << word << endl;
    }
}