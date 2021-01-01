# My solution
```
class Solution:
    def trap(self, height: List[int]) -> int:
        lmax = []
        rmax = []
        
        n = len(height)
        if n == 0:
            return 0
        
        prevmax = [0, height[0]]
        lmax.append(-1)
        for i in range(1, n):
            if height[i] < prevmax[1]:
                lmax.append(prevmax[0])
            else:
                lmax.append(-1)
                prevmax = [i, height[i]]
        
        # print(lmax)
        
        prevmax = [n-1, height[n-1]]
        rmax.append(-1)
        for i in range(n-2, -1, -1):
            if height[i] < prevmax[1]:
                rmax.append(prevmax[0])
            else:
                rmax.append(-1)
                prevmax = [i, height[i]]
                
        rmax = rmax[::-1]
        # print(rmax)
        
        water = 0
        for i in range(n):
            if lmax[i] == -1 or rmax[i] == -1:
                water += 0
            else:
                water += min(height[lmax[i]], height[rmax[i]]) - height[i]
        return water
```

# Solution 2 pointers
```
int trap(vector<int>& height)
{
    int left = 0, right = height.size() - 1;
    int ans = 0;
    int left_max = 0, right_max = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
            ++left;
        }
        else {
            height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
            --right;
        }
    }
    return ans;
}
```
