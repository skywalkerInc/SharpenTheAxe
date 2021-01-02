# O((n+m)log(m+n)) S(1)
```
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        for i in range(n):
            nums1[m+i] = nums2[i]
        return nums1.sort()
        
                
        
```

# O(m+n) S(m)
```
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        nums1cpy = [num for num in nums1[:m]]
        p1 = 0
        p2 = 0
        while p1 < m and p2 < n:
            if nums1cpy[p1] <= nums2[p2]:
                nums1[p1+p2] = nums1cpy[p1]
                p1 += 1
            else:
                nums1[p1+p2] = nums2[p2]
                p2 += 1
        
        if p1 < m:
            while p1 < m:
                nums1[p1+p2] = nums1cpy[p1]
                p1 += 1
        
        if p2 < n:
            while p2 < n:
                nums1[p1+p2] = nums2[p2]
                p2 += 1
        
            
        
```