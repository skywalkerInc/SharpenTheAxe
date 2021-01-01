# My Solution
```
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        rows = len(matrix)
        if rows == 0:
            return matrix
        
        cols = len(matrix[0])
        rowzero = 1
        colzero = 1
        
        for i in range(0,rows):
            for j in range(0,cols):
                if matrix[i][j] == 0 and i==0 and j==0:
                    rowzero = 0
                    colzero = 0
                elif matrix[i][j] == 0 and j == 0:
                    rowzero = 0
                elif matrix[i][j] == 0 and i == 0:
                    colzero = 0
                elif matrix[i][j] == 0:
                    matrix[0][j] = 0
                    matrix[i][0] = 0
                
                
                    
        print(rows, cols, matrix, rowzero, colzero)
        
        #travel rows
        for i in range(1,rows):
            if matrix[i][0] == 0:
                for j in range(1,cols):
                    matrix[i][j] = 0
        
        #travel cols
        for j in range(1,cols):
            if matrix[0][j] == 0:
                for i in range(0, rows):
                    matrix[i][j] = 0
        
        if rowzero == 0:
            for i in range(0, rows):
                matrix[i][0] = 0
        
        if colzero == 0:
            for j in range(0,cols):
                matrix[0][j] = 0
                
```