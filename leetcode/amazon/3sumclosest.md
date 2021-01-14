## O(n2)
```
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums = sorted(nums)
        mindiff = float('inf')
        for i in range(len(nums)-2):
            l = i+1
            r = len(nums)-1
            while l < r:
                tempsum = nums[i] + nums[l] + nums[r]
                diff = target - tempsum
                if tempsum < target:
                    l += 1
                else:
                    r -= 1
                
                if abs(diff) < abs(mindiff):
                    mindiff = diff
        return target - mindiff
```