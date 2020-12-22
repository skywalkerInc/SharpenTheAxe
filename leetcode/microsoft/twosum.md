
``` Two Sum
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        has = {}
        for i, num in enumerate(nums):
            if num in has:
                return [i, has[num]]
            else:
                has[target - num] = i
```
        
        
