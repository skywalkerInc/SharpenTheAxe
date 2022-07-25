# My solution
``` c++
class Solution {
public:
    
    int trap(vector<int>& height) {        
        int n = height.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        
        int left_max = 0;
        for (int i=0; i<n; ++i) {
            left[i] = left_max;
            if (height[i] > left_max) left_max = height[i];
        }
        
        int rightMax = 0;
        for (int i=n-1; i>=0; --i) {
            right[i] = rightMax;
            if (height[i] > rightMax) rightMax = height[i];
            
        }
        
        int res = 0;
        for (int i=0; i<n; i++) {
            if (left[i] > height[i] && right[i] > height[i]) {
                res += min(left[i], right[i]) - height[i];
            }
        }
        
        return res;
        
    }
};
```

```c++
class Solution {
public:
    int trap(vector<int>& height) {        
        int n = height.size();
        int res = 0; 
        int curr=0;
        stack<int> st;
        
        while (curr < n) {
            while (!st.empty() && height[curr] > height[st.top()]) {
                int top = st.top(); 
                st.pop();
                if (st.empty()) 
                    break;
                int dist = curr - st.top() - 1;
                int bound_height = min(height[curr], height[st.top()]) - height[top];
                res += dist * bound_height;
            }
                
            st.push(curr++);
        }
        
        return res;
    }
};

```

# Solution 2 pointers
``` c++
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
