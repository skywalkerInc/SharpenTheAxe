## O(m+n), S(1) 
```
class Solution(object):
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: void Do not return anything, modify nums1 in-place instead.
        """
        # two get pointers for nums1 and nums2
        p1 = m - 1
        p2 = n - 1
        # set pointer for nums1
        p = m + n - 1
        
        # while there are still elements to compare
        while p1 >= 0 and p2 >= 0:
            if nums1[p1] < nums2[p2]:
                nums1[p] = nums2[p2]
                p2 -= 1
            else:
                nums1[p] =  nums1[p1]
                p1 -= 1
            p -= 1
        
        # add missing elements from nums2
        nums1[:p2 + 1] = nums2[:p2 + 1]
```
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