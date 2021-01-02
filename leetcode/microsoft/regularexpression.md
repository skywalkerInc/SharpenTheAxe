# my solution recursive 2650ms very worst
```
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        #print(s, p)
        if len(s) == 0 and len(p) == 0:
            return True
        elif len(s) == 0:
            for i, pat in enumerate(p):
                if i%2 > 0 and pat != '*':
                    return False
            if len(p)%2 > 0:
                return False
            else:
                return True
            
        elif len(p) == 0:
            return False

        if len(p) > 1 and p[1] != '*' and s[0] != p[0] and p[0] != '.':
            return False

        elif len(p) > 1 and p[1] == '*':
            return self.isMatch(s, p[2:]) or self.isMatch(s, p[0] + p)

        elif len(p)> 0 and (p[0] == s[0] or p[0] == '.'):
            return self.isMatch(s[1:], p[1:])
        
        else:
            return False
```