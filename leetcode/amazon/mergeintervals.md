```
import copy
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals = sorted(intervals, key= lambda x:x[0])
        print(intervals)
        if len(intervals) == 0:
            return []
        
        res = []
        temp = copy.copy(intervals[0])
        for i in range(1, len(intervals)):
            #check if current value can merge with temp
            curr_interval = intervals[i]
            if curr_interval[0] <= temp[1]:
                #can be merged
                temp[1] = max(temp[1], curr_interval[1])
            
            else:
                res.append(temp)
                temp = copy.copy(intervals[i])
            print(temp)
        
        res.append(temp)
        return res
        
```