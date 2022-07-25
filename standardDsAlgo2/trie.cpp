/*
Trie:
Also called prefix tree
*/

#include <algorithm>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct TrieNode {
    bool isleaf;
    unordered_map<char, TrieNode*> chars;
    TrieNode(): isleaf(false) {}
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        auto p = root;
        for(auto &ch: word) {
            if (p->chars.count(ch) == 0) {
                p->chars[ch] = new TrieNode();
            }
            p = p->chars[ch];
        }
        p->isleaf = true;
    }
    
    bool search(string word) {
        auto p = root;
        for(auto &ch: word) {
            if (p->chars.count(ch) == 0) {
                return false;
            }
            p = p->chars[ch];
        }
        if (p->isleaf) return true;
        
        return false;
    }
    
    bool startsWith(string prefix) {
        auto p = root;
        for(auto &ch: prefix) {
            if (p->chars.count(ch) == 0) {
                return false;
            }
            p = p->chars[ch];
        }
        return true;
    }
    
    void dfs(TrieNode* root, string& prefix) {
        if (root->isleaf) {
            cout << prefix << endl;
        }
        
        for (auto &ele: root->chars) {
            auto ch = ele.first;
            auto node = ele.second;
            
            prefix += ch;
            dfs(node, prefix);
        }
    }
    
    void wordsByPrefix(string prefix) {
        string word = "";
        
        // get to the prefix end
        auto p = root;
        for (auto &ch: prefix) {
            if (p->chars.count(ch) == 0) {
                cout << "prefix not in trie" << endl;
                return;
            }
            word += ch;
            p = p->chars[ch];
        }
        
        if (p->chars.empty()) {
            cout << "no node after prefix" << endl;
            return;
        }
        
        // run dfs
        dfs(p, word);
    }
};


int main() {
	// Your code goes here;
    Trie trie = Trie();
    trie.insert("app");
    trie.insert("apple");
    trie.insert("apt");
    bool out = trie.search("apple");
    cout << out << endl;
    trie.wordsByPrefix("app");
	return 0;
}
