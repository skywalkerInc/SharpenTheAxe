# My code
```
class Solution:
    def myAtoi(self, s: str) -> int:
        
        def isnum(ch):
            if ord(ch) >= ord('0') and ord(ch) <= ord('9'):
                return True
            else:
                return False
        
        i = 0
        n = len(s)
        sign = 1
        
        while i < n and s[i] == ' ' and (s[i] != '-' or s[i] != '+'):
            i += 1
        
        if i>=n:
            return 0
        
        if s[i] == '-':
            sign = -1
            i += 1
        elif s[i] == '+':
            sign = 1
            i+= 1
        elif not isnum(s[i]):
            return 0
        
        j = 0+i
        while j<n and isnum(s[j]):
            j += 1
        j -= 1
            
        ret = 0
        h = j
        t = 1
        #print(i,j, s[0], s[1])
        while j >= i:
            ret += int(s[j])*t
            j -= 1
            t = t*10
        #print(ret, pow(2, 31))
        if ret >= pow(2,31):
            if sign == -1:
                ret =  pow(2,31)
            else:
                ret = pow(2, 31) - 1
        
        return ret * sign
        
            
```