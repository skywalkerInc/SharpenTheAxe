```
class Solution:
    def romanToInt(self, s: str) -> int:
        
        rc = {'I':1, 'V':5, 'X':10, 'L': 50, 'C':100,'D':500, 'M':1000}
        
        res = 0
        i = len(s) - 1
        while i >= 0:
            curr_val = rc[s[i]]
            
            if s[i] == 'X' or s[i] == 'V':
                if i - 1 >= 0 and s[i-1] == 'I': #next letter exist
                    curr_val -= rc['I']
                    i -= 1
            elif s[i] == 'C' or s[i] == 'L':
                if i - 1 >= 0 and s[i-1] == 'X':
                    curr_val -= rc['X']
                    i -= 1
            elif s[i] == 'M' or s[i] == 'D':
                if i - 1>= 0 and s[i-1] == 'C':
                    curr_val -= rc['C']
                    i -= 1
            
            res += curr_val
            i -= 1
        return res
```

```
class Solution:
    def romanToInt(self, s: str) -> int:
        
        rc = {'I':1, 'V':5, 'X':10, 'L': 50, 'C':100,'D':500, 'M':1000}
        
        res = 0
        i = 0
        while i < len(s):
            
            val = rc[s[i]]
            if i+1 < len(s):
                nextval = rc[s[i+1]]
                if nextval > val:
                    res -= val
                else:
                    res += val
            else:
                res += val
            
            i += 1
        return res
```