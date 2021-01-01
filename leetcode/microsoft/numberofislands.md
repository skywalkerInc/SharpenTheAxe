# bfs solution (slow)
```
from collections import deque
class Solution:
    def restrictedArea(self, i, j, grid):
        if i < 0 or i >= len(grid) or j < 0 or j >= len(grid[0]) or grid[i][j] == "0":
            return True
        else:
            return False
        
    def exploreIsland(self, grid, i, j):
        q = deque([])
        q.append((i,j))
        self.visited[i][j] = 1
        while q:
            outi, outj = q.popleft()
            # print(outi, outj, self.visited[outi][outj])
            for dx, dy in self.dirs:
                ni, nj = outi + dy, outj + dx
                # print(ni, nj)
                if not self.restrictedArea(ni, nj, grid) and self.visited[ni][nj] == 0:
                    q.append((ni, nj))
                    self.visited[ni][nj] = 1
                    
    def numIslands(self, grid: List[List[str]]) -> int:
        rows = len(grid)
        if rows == 0:
            return 0
        
        self.grid = grid
        cols = len(grid[0])
        self.visited = [[0 for i in range(cols)] for j in range(rows)]
        self.dirs = [(0,-1), (0,1), (-1,0), (1,0)]
        total_island = 0
        # for i in range(rows):
        #     print(self.visited[i]) 
            
        for i in range(rows):
            for j in range(cols):
                if (self.visited[i][j]==0) and (grid[i][j] == "1"):
                    # print('exploreisland')
                    self.exploreIsland(grid, i, j)
                    total_island += 1
                    
        return total_island
                    
```

# Dfs solution
```
from collections import deque
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        count=0
        def dfs(i,j):
            grid[i][j]='#'
            #print(i,j)
            if i-1>-1 and grid[i-1][j]=="1":
                dfs(i-1,j)
            if j-1>-1 and grid[i][j-1]=="1":
                dfs(i,j-1)
            if i+1<len(grid) and grid[i+1][j]=="1":
                dfs(i+1,j)
            if j+1<len(grid[0]) and grid[i][j+1]=="1":
                dfs(i,j+1)
            #grid[i][j]="1"
            
            
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]=='1':
                    count+=1
                    dfs(i,j)
        return count
```