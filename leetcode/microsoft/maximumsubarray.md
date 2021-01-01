```
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        
        start = 0
        contsum = nums[0]
        maxsum = nums[0]
        for i, num in enumerate(nums[1:]):
            contsum = contsum + num
            if contsum < num:
                # start = i
                contsum = num
            if contsum > maxsum:
                maxsum = contsum
                
        return maxsum
```