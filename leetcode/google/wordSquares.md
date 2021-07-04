```c++

//O(N* 26^L); N: number of words, L: length of word;
class Solution {
    int k;
    vector<string> words; //can it be pointer? can we use emplace? can it be reference?
    unordered_map<string, vector<string>> prefixMap; // can this be prefix to list of references to word?
public:
    
    void buildPrefixMap() {
        for (auto &word: words) {
            for (int i=0; i<k; i++) {
                prefixMap[word.substr(0,i)].push_back(word);
            }
        }
    }
    
    void backTrack(vector<string>& wordSq, vector<vector<string>>& res, int step) {
        if (step == k) {
            res.push_back(wordSq); //will it copy or pass reference?
        }
        
        string prefix;
        for (auto &word: wordSq) {
            prefix.push_back(word[step]);
        }
        
        for (auto &word: prefixMap[prefix]) {
            wordSq.push_back(word);
            backTrack(wordSq, res, step+1);
            wordSq.pop_back();
        }
    }
    
    vector<vector<string>> wordSquares(vector<string>& words) {
        this->k = words[0].size();
        this->words = words; // will changing this->words will change words?
        
        buildPrefixMap();
        
        vector<vector<string>> res;
        for (auto &word: words) {
            vector<string> wordSq = {word};
            backTrack(wordSq, res, 1);
        }
        
        return res;
    }
};

/*
b a l l
a r e a
l e a d
l a d y
*/

```

```c++ trie
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

class Solution {
    int k;
    vector<string> words; //can it be pointer? can we use emplace? can it be reference?
    unordered_map<string, vector<string>> prefixMap; // can this be prefix to list of references to word?
public:
    
    void backTrack(Trie& trie, vector<string>& wordSq, vector<vector<string>>& res, int step) {
        if (step == k) {
            res.push_back(wordSq); //will it copy or pass reference?
            return;
        }
        
        string prefix;
        for (auto &word: wordSq) {
            prefix.push_back(word[step]);
        }

        vector<string> wordsByPrefix = trie.getWordByPrefix(prefix);
        
        for (auto &word: wordsByPrefix) {
            cout << word << endl;
            wordSq.push_back(word);
            backTrack(trie, wordSq, res, step+1);
            wordSq.pop_back();
        }
    }
    
    vector<vector<string>> wordSquares(vector<string>& words) {
        this->k = words[0].size();
        this->words = words; // will changing this->words will change words?

        Trie trie = Trie(words);
        
        vector<vector<string>> res;
        for (auto &word: words) {
            vector<string> wordSq = {word};
            backTrack(trie, wordSq, res, 1);
        }
        
        return res;
    }
};

/*
b a l l
a r e a
l e a d
l a d y
*/
```