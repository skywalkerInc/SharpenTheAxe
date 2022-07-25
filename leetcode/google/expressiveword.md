```c++
class Solution {
public:
    int getNextCharIndex(string& word, int index) {
        int j = index;
        while (j < word.size() && word[j]==word[index]) j++;
        return j-index;
    }
    
    bool isStretchy(string& s, string& word) {
        if (word.size() == 0) return false;
        
        int i = 0; //s
        int j = 0; //word
        cout << word << endl;
        // cout<< "size: "<< s.size() << " : "<<word.size() <<endl;
        while (i < s.size() && j < word.size()) {
            // printf("i:%d, j:%d\n", i, j);
            if (s[i] == word[j]) {
                int leni = getNextCharIndex(s, i);
                int lenj = getNextCharIndex(word, j);
                // printf("leni:%d, lenj:%d\n", i, j, leni, lenj);
                
                if ((leni < 3 && lenj != leni) || (leni >= 3 && leni <lenj)) {
                    // cout << "returning false" << endl;
                    return false;
                }
                
                i += leni;
                j += lenj;
                
            } else {
                // cout << "string did not match | " << s[i] << " : " << word[j];
                return false;
            }
        }
        
        return i==s.size() && j==word.size();
    }
    
    int expressiveWords(string s, vector<string>& words) {
        if (!s.size() || !words.size()) return 0;
        
        int res = 0;
        for (auto &word: words) {
            if (isStretchy(s, word)) res++;
        }
        return res;
    }
};

/*
s = "heeellooo"
words = ["hello", "hi", "helo"]

h:1  e:3 l:2 o:3
h:1  e:1->3 l:2 o:1->3 hello
h:1  e:1->3 l:1->3 o-1-> helo
h:1  iX


0: h,1



*/
```