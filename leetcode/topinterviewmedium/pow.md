## O(logn)  S(1)
## Cosiders negative power too
```
class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n <0:
            x = 1/x
            n = -n
        
        ans = 1
        curr = x
        while n>0:
            if n%2 == 1:
                ans *= curr
            curr = curr*curr
            n //= 2
            
        return ans
        
        
        
```