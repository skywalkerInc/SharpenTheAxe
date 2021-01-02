## move 0s to left and move 2s to right, the 1s will autoadjust
```
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        p0 = curr = 0
        p2 = len(nums) -1
        
        while curr <= p2:
            
            if nums[curr] == 0:
                nums[p0], nums[curr] = nums[curr], nums[p0]
                p0 += 1
                curr += 1
            elif nums[curr] == 2:
                nums[p2], nums[curr] = nums[curr], nums[p2]
                p2 -= 1
            elif nums[curr] == 1:
                curr += 1
        
        
```