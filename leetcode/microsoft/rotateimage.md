# My Solution
```
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        if n == 0:
            return
        
        fwd = 0
        bwd = n-1
        
        while fwd<bwd:
            h = bwd - fwd + 1
            for i in range(0, bwd-fwd):
                temp = matrix[fwd][fwd+i]
                matrix[fwd][fwd+i] = matrix[bwd-i][fwd]
                matrix[bwd-i][fwd] = matrix[bwd][bwd-i]
                matrix[bwd][bwd-i] = matrix[fwd+i][bwd]
                matrix[fwd+i][bwd] = temp
            
            fwd += 1
            bwd -= 1
        
        
```