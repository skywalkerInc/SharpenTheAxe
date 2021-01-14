```
class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        v1lst = version1.split('.')
        v2lst = version2.split('.')
        i,j=0,0
        while i< len(v1lst) or j < len(v2lst):
            
            n1 = int(v1lst[i]) if i< len(v1lst) else 0
            n2 = int(v2lst[j]) if j < len(v2lst) else 0
            if n1 < n2:
                return -1
            elif n1 > n2:
                return 1
            
            i += 1
            j += 1
        
        return 0
            
```