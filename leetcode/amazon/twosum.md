```
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        has = {}
    
        for i, num in enumerate(numbers):
            if num not in has:
                has[target - num] = i
            else:
                res = [has[num]+1, i+1]
                return res
```