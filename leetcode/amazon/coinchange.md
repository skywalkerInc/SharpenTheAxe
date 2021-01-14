## Top down O(s*n) s is amount and n is number of coins
```
class Solution:
    def rec(self, coins, rem):
        if rem <0:
            return -1
        
        if rem == 0:
            return 0
        
        if self.nc[rem-1] != 0:
            return self.nc[rem-1]
        
        mincoin = float('inf')
        for c in coins:
            res = self.rec(coins, rem-c)
            if res >= 0 and res<mincoin:
                mincoin = res + 1
        self.nc[rem-1] = mincoin if mincoin != float('inf') else -1
        return self.nc[rem-1]
        
    def coinChange(self, coins: List[int], amount: int) -> int:
        if amount < 0:
            return 0
        self.nc = [0]*amount
        return self.rec(coins, amount)
```
## bottoms up
```
class Solution:

    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [float('inf')]*(amount+1)
        dp[0] = 0
        for coin in coins:
            for x in range(coin, amount+1):
                dp[x] = min(dp[x], dp[x-coin] + 1)
        return dp[amount] if dp[amount] != float('inf') else -1
```

## using sorting of coin
```
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        coins.sort(reverse=True)
        self.res = float('inf')
        self.dfs(coins, 0, amount, 0)
        return -1 if self.res == float('inf') else self.res
    
    def dfs(self, coins, index, amount, count):
        if amount == 0:
            self.res = count
            return
            
        if index == len(coins):
            return
        
        coin = coins[index]
        for k in range(amount // coin, -1, -1):
            if count + k >= self.res:
                break
            self.dfs(coins, index + 1, amount - k * coin, count + k)
```

## Queue Based
```
import math

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        if not amount:
            return 0
        
        step = 0
        q = [0]
        seen = [True] + [False] * amount
        
        while q:
            new_q = []
            step += 1
            
            for val in q:
                for c in coins:
                    new_val = val + c
                    if new_val == amount:
                        return step
                    elif new_val < amount and not seen[new_val]:
                        seen[new_val] = True
                        new_q.append(new_val)
            
            q = new_q
        
        return -1
```