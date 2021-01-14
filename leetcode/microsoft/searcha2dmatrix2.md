## easy O(m+n) solution
```
class Solution:
    
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix:
            return False
        
        rows = len(matrix)
        cols = len(matrix[0])
        
        row = rows -1 
        col = 0
        
        while col < cols and row >= 0:
            
            if matrix[row][col] < target:
                col += 1
            elif matrix[row][col] > target:
                row -= 1
            else:
                return True
        
        return False
        
```

## searching along diagonal O(long(n!))
```
class Solution:
    def binarysearch(self, matrix, target, start, verticle):
        lo = start
        hi = len(matrix[0]) - 1 if verticle else len(matrix) -1
        
        while hi >= lo:
            mid = (lo + hi)//2
            if verticle:
                if matrix[start][mid] < target:
                    lo = mid + 1
                elif matrix[start][mid] > target:
                    hi = mid -1
                else:
                    return True
                
            else:
                if matrix[mid][start] < target:
                    lo = mid + 1
                elif matrix[mid][start] > target:
                    hi = mid - 1
                else:
                    return True
        return False
    
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix:
            return False
        
        for i in range(min(len(matrix), len(matrix[0]))):
            verticle_found = self.binarysearch(matrix, target, i, True)
            horizontal_found = self.binarysearch(matrix, target, i, False)
            
            if verticle_found or horizontal_found:
                return True
            
        return False
```

## divide and conquer O(nlongn)
```
class Solution:
    
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix:
            return False
        
        def search_rec(left, up, right, down):
            
            #base cases:
            if left > right or up > down:
                return False
            elif target < matrix[up][left] or target > matrix[down][right]:
                return False
            
            
            #search for suitable row in mid column
            mid = left + (right-left)//2
            row = up
            while row <= down and matrix[row][mid] <= target:
                if matrix[row][mid] == target:
                    return True
                row += 1
            
            # call submatrices where target is possible present
            return search_rec(left, row, mid-1, down) or search_rec(mid+1, up, right, row-1)
            
        
        return search_rec(0,0, len(matrix[0])-1, len(matrix)-1)
            
```