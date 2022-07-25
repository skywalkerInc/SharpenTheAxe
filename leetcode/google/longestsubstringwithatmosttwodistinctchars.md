```c++
class Solution {
public:

    int lengthOfLongestSubstringTwoDistinct(string s) {
        int maxlen = 0;
        int n = s.size();
        int count[128] = {}, l=0, r=0, dist=0;
        
        while (r<n) {
            
            if (++count[s[r++]] == 1) {
                ++dist;
            }
            
            while (dist > 2) {
                char ch = s[l++];
                if (--count[ch] == 0) {
                    --dist;
                }
            }
            
            maxlen = max(maxlen, r-l);
        }
        
        return maxlen;
    }
};


/*
c: 0
a: 2
*/
```

```c++
class Solution {
public:

    int lengthOfLongestSubstringTwoDistinct(string s) {
        int maxlen = 0;
        int n = s.size();
        if (n < 3) {
            return n;
        }
        
        int l=0, r=0;
        map<char, int> lastOccured;
        
        while (r < n) {
            lastOccured[s[r]] = r;
            r++;
            
            if (lastOccured.size() == 3) {
                int minLastOccured = INT_MAX;
                for (auto &obj: lastOccured) {
                    minLastOccured = min(minLastOccured, obj.second);
                }
                lastOccured.erase(s[minLastOccured]);
                l = minLastOccured + 1;
            }
            
            maxlen = max(maxlen, r-l);
        }
        
        return maxlen;
    }
};


/*
c: 0
a: 2
*/
```