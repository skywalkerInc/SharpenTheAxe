# My code  (I)
```
class Solution:
    def reverseWords(self, s: str) -> str:
        
        words = []
        i = 0
        n = len(s)
        
        while i < n:
            st = i
            
            while st < n and s[st] == ' ':
                st += 1
            
            ed = st
            
            while ed < n and s[ed] != ' ':
                ed += 1
            
            if st < ed:
                word = s[st:ed]
                words.append(word)
    
            i = ed
            
        # print(words)
        res = ""
        for word in words[::-1]:
            res += word + ' '
        
        
        return res[0:len(res)-1]
        
            
```

# My code (II)
```
class Solution:
    def reverseWords(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        words = []
        i = 0
        n = len(s)
        
        while i < n:
            st = i
            
            while st < n and s[st] == ' ':
                st += 1
            
            ed = st
            
            while ed < n and s[ed] != ' ':
                ed += 1
            
            if st < ed:
                word = s[st:ed]
                words.append(word)
    
            i = ed
            
        retnew = []
        for i, word in enumerate(words[::-1]):
            retnew += word + [' ']
     
        return retnew[0:len(retnew)-1]
```
# Best

```
class Solution:
    def reverseWords(self, s: str) -> str:
        return " ".join(s.split()[::-1])
```