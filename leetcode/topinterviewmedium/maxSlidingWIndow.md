O(n)
```
#include <deque>
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector <int> res;
        deque <int> indexDq; //will contain index, index with max value always on front
        
        for (int i = 0; i < nums.size(); i++) {
            //exit case
            if (!indexDq.empty() && indexDq.front() == i-k) 
                indexDq.pop_front();
            
            //entry case
            while (!indexDq.empty() && nums[i] > nums[indexDq.back()]) 
                indexDq.pop_back();
            indexDq.push_back(i);
            
            //udpdate res
            if(i >= k-1)
                res.push_back(nums[indexDq.front()]);
            
        }
        
        return res;
    }
};

```