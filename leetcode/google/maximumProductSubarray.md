```c++
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        int maxSoFar = nums[0];
        int minSoFar = nums[0];
        int maxProd = maxSoFar;
        
        for (int i=1; i<nums.size(); i++) {
            int curr = nums[i];
            
            int tempMax = max(curr, max(maxSoFar*curr, minSoFar*curr));
            minSoFar = min(curr, min(maxSoFar*curr, minSoFar*curr));
            maxSoFar = tempMax;
            
            maxProd = max(maxSoFar, maxProd);
        }
        
        return maxProd;
    }
};

```