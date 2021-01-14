```
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if needle == '':
            return 0
        
        if len(needle) > len(haystack):
            return -1
        
        nh = len(haystack)
        nn = len(needle)
        
        for i in range(0,nh-nn+1):
            if haystack[i] == needle[0]:
                #match all string after
                if haystack[i+1:i+1+nn-1] == needle[1:nn]:
                    return i
        
        return -1
```