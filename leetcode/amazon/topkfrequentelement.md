```
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        if k == len(nums):
            return nums
        
        #get frequency
        freq = Counter(nums)
        print(freq)
        #put in heap
        q = []
        for num in freq:
            heapq.heappush(q, (-freq[num], num))
        print(q)
        #get k from heap
        res = []
        for i in range(k):
            res.append(heapq.heappop(q)[1])
            
        return res
        
```