```
class Solution:
    def rec(self, row, col, index):
        #match found
        if index == self.wlen:
            return True
        
        #check if row col are correct and cell value matches suffix start
        if row < 0 or col < 0 or row>=self.nrow or col>=self.ncol or self.board[row][col] != self.word[index]:
            return False
        
        #mark board visited
        temp = self.board[row][col]
        self.board[row][col] = '#'
        
        #move to other directions
        for row_offset, col_offset in [(0,1), (0,-1), (1,0), (-1,0)]:
            if self.rec(row+row_offset, col+col_offset, index+1):
                return True
        
        self.board[row][col] = temp
        return False
        
    def exist(self, board: List[List[str]], word: str) -> bool:
         
        self.nrow = len(board)
        if self.nrow == 0:
            return False
        
        self.ncol = len(board[0])
        self.wlen = len(word)
        self.board = board
        self.word = word
        
        for row in range(self.nrow):
            for col in range(self.ncol):
                if self.rec(row, col, 0):
                    return True
        
        return False
        
```