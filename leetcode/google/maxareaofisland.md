
## 20min
## debugging: 20min

``` c

int trav(int** grid, int gridSize, int*gridColSize, int row, int col) {
    
    if (row<0 || row>=gridSize || col<0 || col>=*gridColSize ||
        grid[row][col]==2 || grid[row][col]==0 ) {
        return 0;
    }
    
    grid[row][col] = 2;
    int area = 1;

    if(row + 1 < gridSize) {
        area += trav(grid, gridSize, gridColSize, row+1, col);
    }

    if(row -1 >= 0) {
        area += trav(grid, gridSize, gridColSize, row-1, col);
    }

    if(col + 1 < *gridColSize) {
        area += trav(grid, gridSize, gridColSize, row, col+1);
    }

    if(col - 1 >= 0) {
        area += trav(grid, gridSize, gridColSize, row, col-1);
    }   
    
    return area;
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    int maxArea = 0;
    
    for (int row = 0; row < gridSize; row++) {
        for (int col = 0 ; col < *gridColSize; col++) {
            int area = 0;
            
            area = trav(grid, gridSize, gridColSize, row, col);    
            
            maxArea = fmax(area, maxArea);
        }
    }
    
    return maxArea;
}
```