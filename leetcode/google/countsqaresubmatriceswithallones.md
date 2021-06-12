## 25mins (problem solution)
> 25mins (minor debugging)
> missed increasing count of square when top left is 0



``` c++

int countSquares(int** matrix, int matrixSize, int* matrixColSize){
    int colSize = *matrixColSize;
    if (colSize <= 0) return 0;
    
    int rowSize = matrixSize;
    // printf("%d, %d, %d\n",matrixSize, rowSize, colSize);
    int sqSubCount = 0;
    
    int **count = (int **)malloc(rowSize * sizeof(int *));
    for (int i = 0; i<rowSize; i++) {
        
        count[i] = (int *)malloc(colSize * sizeof(int));
        
        for (int j =0; j<colSize; j++) {
            
            count[i][j] = 0;
            if (i == 0 || j ==0) {
                count[i][j] = matrix[i][j];
                if (count[i][j] == 1){
                    sqSubCount++;    
                }
            }
            // printf("%d ", count[i][j]);
        }
        // printf("\n");
    }
    // printf("sqSuCount: %d\n", sqSubCount);
    
    
    for (int row =1; row<rowSize; row++) {
        for (int col = 1; col < colSize; col++) {
            int subCount = 1;
            
            if (matrix[row][col] == 0) {
                count[row][col] = 0;
                // printf("%d,%d: %d, %d, %d\n",row, col, count[row][col], subCount, sqSubCount);
                continue;
            }
            
            if (count[row-1][col-1] == 0) {
                count[row][col] = subCount;
                sqSubCount += subCount;
                // printf("%d,%d: %d, %d, %d\n",row, col, count[row][col], subCount, sqSubCount);
                continue;
            }
            
            for (int k = 0; k < count[row-1][col-1]; k++) {
                int top = matrix[row-k-1][col];
                int left = matrix[row][col-k-1];
                
                if (top == 0 || left == 0) break;
                
                subCount++;
            }
            
            sqSubCount += subCount;
            count[row][col] = subCount;
            
            // printf("%d,%d: %d, %d, %d\n",row, col, count[row][col], subCount, sqSubCount);
        }
    }
    
    return sqSubCount;
}
```