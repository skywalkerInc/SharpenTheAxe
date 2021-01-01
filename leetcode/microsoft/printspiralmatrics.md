# My Code
```
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        
        rows = len(matrix)
        if rows == 0:
            return []
        cols = len(matrix[0])
        
        res = []
        
        
        rowup = 0
        rowdown = rows-1
        colleft = 0
        colright = cols-1
        while rowup <= rowdown and colleft<=colright:
            
            #move right in rowup row for colleft to colright
            #increament rowup
            print(rowup, rowdown, colleft, colright)
            for i in range(colleft, colright+1):
                res.append(matrix[rowup][i])
            # rowup += 1
            
            #move down in colright col for for rowup to rowdown
            #decreament colright
            print(rowup, rowdown, colleft, colright)
            for i in range(rowup+1, rowdown+1):
                res.append(matrix[i][colright])
            # colright -= 1
            
            #move left in rowdown for colright to colleft
            #decreament rowdown
            if rowup < rowdown and colleft < colright:
                print(rowup, rowdown, colleft, colright)
                for i in range(colright-1, colleft , -1):
                    res.append(matrix[rowdown][i])
                # rowdown -= 1


                #move up in colleft for rowdown to rowup
                #increament colleft
                print(rowup, rowdown, colleft, colright)
                for i in range(rowdown, rowup, -1):
                    res.append(matrix[i][colleft])
                # colleft += 1
            
            rowup += 1
            rowdown -= 1
            colright -= 1
            colleft += 1
            
            
        return res    
            
            
        
```
