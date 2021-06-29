```c++

class Solution {
public:
    const int VISITED = 1;
    const int NOT_VISITED = 0;
    int maxLen = 0;
    vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    
    int dfs(vector<vector<int>> &matrix, int row, int col, vector<vector<int>> &cache) {
        if (cache[row][col] != 0) return cache[row][col];
        
        for (auto &dir: dirs) {
            int x = dir[0] + row, y = dir[1] + col;
            
            if (x>=0 && x<matrix.size() && y>=0 && y<matrix[0].size() && matrix[x][y] > matrix[row][col]) {
                cache[row][col] = max(cache[row][col], dfs(matrix, x, y, cache));
            }
        }
        
        return ++cache[row][col];
            
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return 0;
        
        int m = matrix.size(), n = matrix[0].size(); //row, col
        vector <vector <int>> cache(m, vector<int>(n, 0));
        int ans = 0;
        
        // Get longest path for all row col
        for (int row = 0; row<m; row++) {
            for (int col=0; col<n; col++) {
                ans = max(ans, dfs(matrix, row, col, cache));
            }
        }
        
        return ans;

    }
};

```