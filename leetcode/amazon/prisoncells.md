```
class Solution:
    def prisonAfterNDays(self, cells: List[int], N: int) -> List[int]:
        seen = dict()
        is_fast_forward = False
        while N>0:
            
            if not is_fast_forward:
                state_key = tuple(cells)
                if state_key in seen:
                    N %= seen[state_key] - N
                    is_fast_forward = True
                else:
                    seen[state_key] = N
            
            
            
            if N>0:
                N -= 1
                next_day_cells = self.nextDay(cells)
                cells = next_day_cells
        
        return cells
        
    
    def nextDay(self, cells: List[int]):
        ret = [0]
        for i in range(1, len(cells)-1):
            ret.append(int(cells[i-1] == cells[i+1]))
        ret.append(0)
        return ret
```