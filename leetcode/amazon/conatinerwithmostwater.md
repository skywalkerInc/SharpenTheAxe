## O(n)
```
class Solution:
    def maxArea(self, height: List[int]) -> int:
        
        l = 0
        r = len(height) -1
        maxarea = 0
        while l < r:
            maxarea = max(min(height[l], height[r]) * (r-l) , maxarea)
            if height[l] > height[r]:
                r -= 1
            else:
                l += 1
        return maxarea
```