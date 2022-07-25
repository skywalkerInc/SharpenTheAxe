#include <bits/stdc++.h>
using namespace std;

typedef int NODE;
typedef int DIST;

class Dset {
public:
    vector<NODE> parent;
    vector<int> rank;
    Dset(int size): parent{vector<NODE>(size+1, -1)}, rank{vector<int>(size+1, 0)} {}

    // Find the root of u
    int find(int u) {
        if (parent[u] < 0) return u;
        return parent[u] = find(parent[u]);
    }

    // Merge 2 nodes
    bool merge(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv) return false; // no merging needed
        
        parent[pu] = pv;

        return true;

    }
};

class TrieNode {
public:
    bool isLeaf;
    vector<TrieNode*> chars;
    TrieNode(): isLeaf(false), chars{vector<TrieNode*>(26, nullptr)} {}
};

class Trie {
    TrieNode* root;
public:
    Trie(vector<string>& words) {
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

    bool search(string word) {
        TrieNode* iter  = root;
        for (auto &ch: word) {
            if(!iter) break;
            int pos = ch - 'a';
            iter = iter->chars[pos];
        }
        if (iter && iter->isLeaf) return true;
        return false;
    }
    vector<string> out;

    void getAllWord(TrieNode* root, string word) {
        if (root->isLeaf) {
            out.push_back(word);
        }
        
        for (int i=0; i<26; ++i) {
            if (root->chars[i]) {
                word.push_back(char('a' + i));
                getAllWord(root->chars[i], word);
                word.pop_back();
            }
        }
    }

    void getWordsByPrefix(string prefix) {
        TrieNode* iter = root;
        for(auto &ch: prefix) {
            if (!iter) break;

            int pos = ch - 'a';
            iter = iter->chars[pos];
        }

        if(iter) getAllWord(iter, prefix);
    }


};

class Rough{
  
public:
    Rough() {}

    void Solution() {
        printAdjList(adj);
    
    }
};