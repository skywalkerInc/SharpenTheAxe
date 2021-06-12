```
import heapq
class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        if len(intervals) == 0:
            return 0
        
        intervals = sorted(intervals, key=lambda x:x[0]) #sort based on start time
        
        q = []
        heapq.heappush(q, intervals[0][1])
        curr_room = 1
        minroom = 1
        for interval in intervals[1:]:
            if interval[0] < q[0]:
                heapq.heappush(q, interval[1])
                
            else:
                heapq.heappop(q)
                heapq.heappush(q, interval[1])
            curr_room = len(q)
            minroom = max(minroom, curr_room)
        return minroom
                
                
            
            
        
```