## Calculator O(1) S(1)
```
from math import e, log
class Solution:
    def mySqrt(self, x: int) -> int:
        if x < 2:
            return x
        
        #mySqrt(x) = e^(1/2 * logx)
        left = int(e**(0.5*log(x)))
        right = left + 1
        return left if right*right >x else right
```

## Binary Search O(logn) S(1)
```
class Solution:
    def mySqrt(self, x: int) -> int:
        if x < 2:
            return x
        
        l, r = 2, x//2
        
        while l <= r:
            mid = l + (r-l)//2
            num = mid*mid
            
            if num > x:
                r = mid-1
            elif num <x:
                l = mid + 1
            else:
                return mid
        
        return r
```


## Bitwise O(logn), S(longn)
```
class Solution:
    def mySqrt(self, x: int) -> int:
        if x < 2:
            return x
        
        #mySqrt(x) = 2 * mySqrt(x/4)
        left = self.mySqrt(x>>2)<<1
        right = left + 1
        return left if right*right >x else right
```