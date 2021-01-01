# could not solve

## leetcode solution
## O(NKlogK)
```
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res = []
        for word in strs:
            res[tuple(sorted(word))].append(word)
        print(res)
```

## O(NK)
```
from collections import defaultdict
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res = defaultdict(list)
        for word in strs:
            count = [0]*26
            for ch in word:
                count[ord(ch) - ord('a')] += 1
            
            res[tuple(count)].append(word)
        
        return res.values()
```
