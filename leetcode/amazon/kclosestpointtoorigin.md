```
class Solution:
    def kClosest(self, points: List[List[int]], K: int) -> List[List[int]]:
        
        q = []
        for point in points:
            x, y = point
            d = sqrt(x*x + y*y)
            heapq.heappush(q, (d, point))
        
        res = []
        for i in range(K):
            res.append(heapq.heappop(q)[1])
        return res
            
```