## O(n)
```
from collections import defaultdict
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if not s or not t:
            return ""
        
        #make dict to contain count of char in t
        dict_t = Counter(t)
        
        #number of unique character in t
        unique_t = len(dict_t)
        
        
        #initialize window for s
        dict_win = {} #contain count of char in window
        
        #variable to store number of chars found
        found_s = 0 
        
        #pointer of window start and end
        win_st = 0
        win_ed = 0
        
        #store min length
        minlen = float('inf')
        ret_st = None
        ret_ed = None
        
        print(dict_t, )
        
        while win_ed < len(s):
            ch = s[win_ed]
            dict_win[ch] = dict_win.get(ch, 0) + 1
            
            #increase win_ed if found_s < unique_t
            if ch in dict_t and dict_win[ch] == dict_t[ch]:
                found_s += 1
            
            #if found_s == unique_t, move win_st till found_s is less then unique_t
            while win_st <= win_ed and found_s == unique_t:
                ch = s[win_st]
                
                #update return start and end based on length of window
                if win_ed - win_st + 1 < minlen:
                    minlen = win_ed - win_st + 1
                    ret_st = win_st
                    ret_ed = win_ed
                
                #decrease count of ch in window
                dict_win[ch] -= 1
                if ch in dict_t and dict_win[ch] < dict_t[ch]:
                    found_s -= 1
                
                win_st += 1
            win_ed += 1
        
        return "" if minlen == float('inf') else s[ret_st:ret_ed+1]
            
            
        
        #return window with return start and end
```