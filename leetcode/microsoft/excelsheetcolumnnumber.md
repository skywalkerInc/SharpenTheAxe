```
class Solution:
    def titleToNumber(self, s: str) -> int:
        res = 0
        base = 26
        for i, ch in enumerate(s):
            res = res*26 + (ord(ch) - ord('A') + 1)
        return res
```