# My Solution O(n2) S(n2) 
```
n = len(s)
        dp = [[0]*(n+1) for i in range(n+1)]
        
        maxlen = 0
        start = 0
        end = 0
        
        for i in range(n-1,-1,-1):
            for j in range(i, n):
                
                if i == j:
                    dp[i][j] = 1
                elif j-i == 1 and s[i] == s[j]:
                    dp[i][j] = 1
                elif j-i == 2 and s[i] == s[j]:
                    dp[i][j] = 1
                elif j-i > 2 and s[i] == s[j] and dp[i+1][j-1] == 1:
                    dp[i][j] = 1
                
                if dp[i][j] == 1:
                    if j-i + 1 >= maxlen:
                        maxlen = j-i + 1
                        start = i
                        end = j
                        
                # print(i,j, dp[i][j])
        # print(maxlen, start, end, s[start:end+1])
        return s[start:end+1]
```

# Best Solution (seen by solutions)
```
def getlen(self, s: str, left, right):
        left = left
        right = right
        
        while left>=0 and right<len(s) and s[left] == s[right]:
            left -= 1
            right += 1
        
        return right - left - 1
    
    def longestPalindrome(self, s: str) -> str:
        if s == None or len(s) == 0:
            return ""
        
        start = 0
        end = 0
        
        for i in range(0, len(s)-1):
            len1 = self.getlen(s, i, i)
            len2 = self.getlen(s, i, i+1)
            
            maxlen = max(len1, len2)
            
            if maxlen > end - start + 1:
                start = int(i - int((maxlen - 1)/2))
                end = int(i + int(maxlen/2))
            
        
        return s[start:end+1]
```