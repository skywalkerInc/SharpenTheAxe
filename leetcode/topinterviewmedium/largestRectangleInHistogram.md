## O(n) O(n)
```
#include <stack>
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack <int> indexSt;
        
        int hsize = heights.size();
        
        for (int i=0; i<hsize; i++) {
            
            while ((!indexSt.empty()) && (heights[i] < heights[indexSt.top()])) {
                int height = heights[indexSt.top()]; indexSt.pop();
                int stTop = -1;
                if (!indexSt.empty()) {
                    stTop = indexSt.top();
                }
                int dist = i - stTop - 1;
                int area = dist * height;
                
                maxArea = max(maxArea, area);
            }
            
            indexSt.push(i);
        }
        
        while (!indexSt.empty()) {
            int height = heights[indexSt.top()]; indexSt.pop();
            int stTop = -1;
            if (!indexSt.empty()) {
                stTop = indexSt.top();
            }
            int dist = hsize - stTop - 1;
            int area = dist * height;

            maxArea = max(maxArea, area);
        }
        
        return maxArea;
    }
};
 
```


## TLE
```
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        
        for(int i=0; i<heights.size();i++) {
            
            int currheight = heights[i];
            
            for (int j=i; j>=0;j--) {
                int dist = i - j + 1;
            
                if (heights[j] < currheight) {
                    currheight = heights[j];
                }
                
                int tempres = currheight * dist;
                
                if(tempres > maxArea) {
                    maxArea = tempres;
                }
            }
        }
        
        return maxArea;
    }
};

class Solution {
public:
    int calculate(vector<int>& heights, int start, int end) {
        if (start > end) return 0;
        
        //find index with min height
        int min_index = start;
        for (int i = start; i< end+1; i++) {
            if (heights[i] < heights[min_index]) {
                min_index = i;
            }
        }
        
        return max({heights[min_index] * (end - start + 1), 
                  calculate(heights, start, min_index-1),
                  calculate(heights, min_index+1, end)});
    }
    
    int largestRectangleArea(vector<int>& heights) {
        return calculate(heights, 0, heights.size()-1);
    }
};
```