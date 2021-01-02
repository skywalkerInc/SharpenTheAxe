# Backtracking solution O(min(s, p)), S(1)
```
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        
        s_len, p_len = len(s), len(p)
        s_idx, p_idx = 0, 0
        star_idx, temp_s_idx = -1, -1
        
        while s_idx < s_len:
            if p_idx < p_len and p[p_idx] in ['?', s[s_idx]]:
                s_idx += 1
                p_idx += 1
            
            elif p_idx < p_len and p[p_idx] == '*':
                star_idx = p_idx
                temp_s_idx = s_idx
                p_idx += 1
            
            elif star_idx == -1:
                return False
            
            else:
                s_idx = temp_s_idx + 1
                p_idx = star_idx + 1
                temp_s_idx = s_idx
        
        
        return all(x == '*' for x in p[p_idx:])
```

# DP Solution O(SP)
```
class Solution:
    def isMatch(self, s, p):
        s_len = len(s)
        p_len = len(p)
        
        # base cases
        if p == s or p == '*':
            return True
        if p == '' or s == '':
            return False
        
        # init all matrix except [0][0] element as False
        d = [ [False] * (s_len + 1) for _ in range(p_len + 1)]
        d[0][0] = True
        
        # DP compute 
        for p_idx in range(1, p_len + 1):
            # the current character in the pattern is '*'
            if p[p_idx - 1] == '*':
                s_idx = 1
                # d[p_idx - 1][s_idx - 1] is a string-pattern match 
                # on the previous step, i.e. one character before.
                # Find the first idx in string with the previous math.
                while not d[p_idx - 1][s_idx - 1] and s_idx < s_len + 1:
                    s_idx += 1
                # If (string) matches (pattern), 
                # when (string) matches (pattern)* as well
                d[p_idx][s_idx - 1] = d[p_idx - 1][s_idx - 1]
                # If (string) matches (pattern), 
                # when (string)(whatever_characters) matches (pattern)* as well
                while s_idx < s_len + 1:
                    d[p_idx][s_idx] = True
                    s_idx += 1
            # the current character in the pattern is '?'
            elif p[p_idx - 1] == '?':
                for s_idx in range(1, s_len + 1): 
                    d[p_idx][s_idx] = d[p_idx - 1][s_idx - 1] 
            # the current character in the pattern is not '*' or '?'
            else:
                for s_idx in range(1, s_len + 1): 
                    # Match is possible if there is a previous match
                    # and current characters are the same
                    d[p_idx][s_idx] = \
                    d[p_idx - 1][s_idx - 1] and p[p_idx - 1] == s[s_idx - 1]  
                                                               
        return d[p_len][s_len]
```