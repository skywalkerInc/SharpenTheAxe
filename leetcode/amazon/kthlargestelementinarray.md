```
import heapq
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
    
        q = []
        for i in range(k):
            heapq.heappush(q, nums[i])
            
        for num in nums[k:]:
            out = heapq.heappop(q)
            if num > out:
                heapq.heappush(q,num)
            else:
                heapq.heappush(q, out)
        return heapq.heappop(q)
            
```