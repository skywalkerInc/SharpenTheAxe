## strictly increasing
```
class Solution:
    def findMin(self, nums: List[int]) -> int:
        
        if nums[-1] > nums[0]:
            return nums[0]
        
        l = 0
        r = len(nums) -1
        
        while l < r:
            mid = l + (r-l)//2
            
            if nums[mid] < nums[0]:  #move left
                r = mid
            elif nums[mid] >= nums[0]: #move right
                l = mid + 1
        
        return nums[l]
            
                 
                
```

## non strictly increasing
```
class Solution:
    def findMin(self, nums: List[int]) -> int:
       
        l = 0
        r = len(nums) -1
        
        while l < r:
            mid = l + (r-l)//2
            
            if nums[mid] < nums[r]:  #move left
                r = mid
            elif nums[mid] > nums[r]: #move right
                l = mid + 1
            else:
                r -= 1
                
        return nums[l]
            
```
