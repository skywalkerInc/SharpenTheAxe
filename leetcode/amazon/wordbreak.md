O(n3)
```
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        wordDictSet = set(wordDict)
        n = len(s)
        dp = [False]*(n + 1) #0th will be empty string, ith index in dp is end of word
        dp[0] = True
        
        for i in range(1, n+1): #end of word
            for j in range(0, i): #start of word
                if dp[j] and s[j:i] in wordDictSet:
                    dp[i] = True
                    break
        return dp[-1]
```