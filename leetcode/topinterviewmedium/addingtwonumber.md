## O(1) S(1)
```
class Solution:
    def getSum(self, a: int, b: int) -> int:
        mask = 0xFFFFFFFF
        
        #b: carry, a:ans without carry
        while b!=0:
            a, b = (a^b) & mask, ((a&b) << 1)&mask
        
        max_int = 0x7FFFFFFF
        return a if a<max_int else ~(a^mask)
```