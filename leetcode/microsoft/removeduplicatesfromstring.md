```
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        
        luni = (0,nums[0])
        total = 1
        for i, num in enumerate(nums[1:]):
            if num != luni[1]:
                #move the number near to last uni
                #update luni
                nums[luni[0] + 1] = num
                total += 1
                luni = (luni[0] + 1, num)
        print(total)
        return total
                
                
```