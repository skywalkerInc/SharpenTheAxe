```
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        if n == 0:
            return ['']
        ans = []
        
        for c in range(n):
            for left in self.generateParenthesis(c):
                for right in self.generateParenthesis(n-1-c):
                    ans.append('({}){}'.format(left, right))
        return ans
```

```
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        
        ans = []
        def backtrack(s='', left=0, right=0):
            if len(s) == 2*n:
                ans.append(s)
                return
            
            if left < n:
                backtrack(s + '(', left+1, right)
            if right < left:
                backtrack(s + ')', left, right+1)
        
        backtrack()
        return ans
```