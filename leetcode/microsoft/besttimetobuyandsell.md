```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) == 0:
            return 0
        
        lmin = prices[0]
        maxprofit = 0
        
        for price in prices[1:]:
            if price < lmin:
                lmin = price
            profit = price - lmin
            if profit > maxprofit:
                maxprofit = profit
        return maxprofit
        
        #left min
#         lmin = []
#         temp = prices[0]
#         lmin.append(prices[0])
#         for price in prices[1:]:
#             if price <= temp:
#                 temp = price
#             lmin.append(temp)
            
#         #right max
#         temp = prices[len(prices)-1]
#         lmax = []
#         lmax.append(prices[-1])
#         for price in prices[::-1][1:]:
#             if price >= temp:
#                 temp = price
#             lmax.append(temp)
#         lmax = lmax[::-1]
#         #find max of difference if right max> left min
#         mp = 0
#         for i in range(len(prices)):
#             if lmax[i] - lmin[i] > mp:
#                 mp = lmax[i] - lmin[i]
        
#         return mp
```