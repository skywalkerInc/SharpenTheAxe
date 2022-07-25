```c++
class Solution {
public:
    // ab## | c#d#
    bool backspaceCompare(string s, string t) {
        int n=s.size(), m = t.size();
        int i=n-1, j=m-1;
        int skipi=0, skipj=0;
        
        while (i>=0 || j>=0) {
            while (i>=0) {
                if (s[i] == '#') {skipi++;  i--;}
                else if (skipi>0) {skipi--; i--;}
                else break;
            }
            
            while (j>=0) {
                if (t[j] == '#') {skipj++; j--;}
                else if (skipj > 0) {skipj--; j--;}
                else break;
            }
            
            if (i>=0 && j>=0 && s[i] != t[j]) return false;
            
            if (i>=0 != j>=0) return false;
            
            i--; j--;
        }
        
        return true;
        
    }
};

```