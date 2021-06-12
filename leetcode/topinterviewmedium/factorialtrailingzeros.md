```
class Solution:
    def trailingZeroes(self, n: int) -> int:
        zeros=0
        while n>4:
            zeros=zeros+int(n/5)
            n=n/5
        
        return zeros
        
```