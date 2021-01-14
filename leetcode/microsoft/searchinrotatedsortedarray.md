```
class Solution:
    def search(self, nums: List[int], target: int) -> int:  
        if len(nums) == 1 and nums[0] == target:
            return 0
            
        l = 0
        r = len(nums) -1
        
        targetsect = (target - nums[0]) >= 0 #True: left, False: right
        while l <= r:
            
            mid = l + (r-l)//2
            
            if nums[mid] == target:
                return mid
            
            elif nums[mid] >= nums[l]: 
                if target >= nums[l] and target < nums[mid]:
                    r = mid - 1
                else:
                    l = mid+1
            else:
                if target <= nums[r] and target > nums[mid]:
                    l = mid + 1
                else:
                    r = mid -1
            
            
        return -1
```