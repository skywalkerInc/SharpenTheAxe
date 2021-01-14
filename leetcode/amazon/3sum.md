## with hasset O(n2) S(n)
```
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        ret = set()
        
        for i in range(0,len(nums)-2):
            remsum = 0 - nums[i]
            hasmap = {}
            # print(remsum)
            #find 2 numbers whose sum is remsum
            for j in range(i+1,len(nums)):
                # print(hasmap, j, nums[j])
                if nums[j] not in hasmap:
                    hasmap[remsum - nums[j]] = j
                else:
                    temp = [nums[i], nums[hasmap[nums[j]]], nums[j]]
                    ret.add(tuple(sorted(temp)))
        # print(ret)                    
        return list(ret)
```

## Better handling dups O(n2) S(n)
```
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res, dups = set(), set()
        seen = {}
        for i, val1 in enumerate(nums):
            if val1 not in dups:
                dups.add(val1)
                for j, val2 in enumerate(nums[i+1:]):
                    complement = -val1 - val2
                    if complement in seen and seen[complement] == i:
                        res.add(tuple(sorted((val1, val2, complement))))
                    seen[val2] = i
        return res
```