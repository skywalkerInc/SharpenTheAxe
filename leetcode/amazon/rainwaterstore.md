```
class Solution:
    def trap(self, height: List[int]) -> int:
        left, right = 0, len(height)-1
        leftmax, rightmax = 0, 0
        ret = 0
        while left<right:
            if height[left] < height[right]:
                if height[left] >= leftmax:
                    leftmax = height[left]
                else:
                    ret += (leftmax - height[left])
                left += 1
            else:
                if height[right] >= rightmax:
                    rightmax = height[right]
                else:
                    ret += (rightmax - height[right])
                right -= 1
        return ret
```