
```
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        xor = 0
        for i in range(1,n+1):
            xor ^= i
        
        res = xor
        for i in range(n):
            res ^= nums[i]
        return res
            
            
```
## elegant solution
```
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        res = len(nums)
        for i in range(len(nums)):
            res ^= nums[i]^i
        return res
            
            
```