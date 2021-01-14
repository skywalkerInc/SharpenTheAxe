```
class Solution:
    def firstUniqChar(self, s: str) -> int:
        hasmap = Counter(s)
        for i, ch in enumerate(s):
            if hasmap[ch] == 1:
                return i
        return -1
```