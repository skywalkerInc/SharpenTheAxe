# tle solution
## O(n2) S(n2)
```
class Solution:
    def recLIS(self, nums, prevpos, curpos):
        if curpos == len(nums):
            return 0
        
        if self.cache[prevpos+1][curpos] >= 0:
            return self.cache[prevpos+1][curpos]
        
        taken = 0
        if prevpos < 0 or nums[curpos] > nums[prevpos]:
            taken = 1 + self.recLIS(nums, curpos, curpos + 1)
            
        nottaken = self.recLIS(nums, prevpos, curpos + 1)
        
        self.cache[prevpos+1][curpos] = max(taken, nottaken)
        
        return max(taken, nottaken)
        
    def lengthOfLIS(self, nums: List[int]) -> int:
        self.cache = [[-1 for i in range(len(nums)+1)] for j in range(len(nums))]
        return self.recLIS(nums, -1, 0)
```

# DP solution
## O(n2) S(n)
```
class Solution:

    def lengthOfLIS(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        
        dp = [0]*len(nums) #length of longest sequesnce till i including i
        dp[0] = 1
        ret = 1
        for i in range(1, len(nums)):
            tempsol = 0
            for j in range(0, i):
                if nums[i] > nums[j]:
                    tempsol = max(tempsol, dp[j])
            dp[i] = 1 + tempsol
            ret = max(ret, dp[i])
        return ret
            
```

# DP with binary search (unique)
## O(nlogn)  S(n)
```
import bisect 
class Solution:

    def lengthOfLIS(self, nums: List[int]) -> int:
        
        dp = [0]*len(nums)
        retlen = 0
        for num in nums:
            pos = bisect.bisect_left(dp, num, 0, retlen)
            print(num, pos)
            if pos < 0:
                pos = 0

            dp[pos] = num
            if pos == retlen:
                retlen += 1
        return retlen
        
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
         
        dp = [0]*len(nums)
        size = 0
        
        for num in nums:
            i, j = 0, size
            
            while i < j:
                mid = (i+j)//2
                if dp[mid] < num:
                    i = mid + 1
                else:
                    j = mid 
        
            dp[i] = num
            if i == size:
                size += 1
        
        return size
```