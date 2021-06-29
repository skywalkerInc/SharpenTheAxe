#include<bits/stdc++.h>
using namespace std;

class patternSearch {
};

class KMP: patternSearch {
public:
    vector<int> lps;

    void computeLps(string &pattern) {
        lps = vector<int>(pattern.size(), 0);
        int len=0;
        lps[0] = 0;
        int i=1;
        while (i<pattern.size()) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len-1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    
    bool searchPattern(string &pattern, string &text) {
        computeLps(pattern);
        int i =0;
        int j =0;
        while (i < text.size()) {
            if (pattern[j] == text[i]) {
                j++;
                i++;
            }
            if (j == pattern.size()) {
                return true; //returning first match
                j = lps[j-1];
            } else if (i < pattern.size() && pattern[j] != text[i]) {
                if (j != 0) {
                    j = lps[j-i];   
                } else {
                    i = i+1;
                }
            }
        }

    }
};
