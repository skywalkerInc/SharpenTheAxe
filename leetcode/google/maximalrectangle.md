```
#include <stack>
class Solution {
public:
    int maxAreaHistogram(int* heights, int size) {
        stack<int> st;
        st.push(-1);
        int curr = 0;
        int maxArea = 0;
        while (curr < size) {
            
            while (st.top() != -1 && heights[curr] <= heights[st.top()]) {
                int top = st.top(); st.pop();
                int dist = curr - st.top() - 1;
                int height = heights[top];
                // printf("top: %d, dist: %d, height: %d\n", top, dist, height);
                int area = dist * height;
                maxArea = max(area, maxArea);
            }
                
            st.push(curr);
            curr++;
        }
        
        while (st.top() != -1) {
            int top = st.top(); st.pop();
            int dist = curr - st.top() - 1;
            int height = heights[top];
            int area = dist * height;
            maxArea = max(area, maxArea);
        }
        
        
        return maxArea;
        
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int maxArea = 0;
        
        int rowSize = matrix.size();
        if (rowSize == 0) return 0;
        int colSize = matrix[0].size();
        
        int *histogram = new int[colSize];
        for(int i = 0; i< colSize; i++) {
            histogram[i] = 0;
        }
        
        for(int i=0; i<rowSize; i++) {
            
            for(int j=0; j<colSize; j++) {
                histogram[j] = (matrix[i][j] == '1') ? histogram[j] +1 : 0;
            }
            
            maxArea = max(maxArea, maxAreaHistogram(histogram, colSize));
        }
        
        return maxArea;
        
    }
};
```