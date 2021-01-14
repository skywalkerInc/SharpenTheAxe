## O(n) S(n)
```
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        prefix = []
        temp = 1
        for i in range(n):
            temp = temp*nums[i]
            prefix.append(temp)
        print(prefix)
        
        postfix = []
        temp = 1
        for i in range(n-1, -1, -1):
            temp = temp*nums[i]
            postfix.append(temp)
        postfix = postfix[::-1]
        print(postfix)
        
        output = [1]*n
        for i in range(1,n-1):
            output[i] = prefix[i-1] * postfix[i+1]
        output[0] = postfix[1]
        output[n-1] = prefix[n-2]
        return output
```

## O(n) S(1) output memory is not counted as extra
```
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        output = [1]*n
        
        #compute left in output
        temp = 1
        for i in range(n):
            temp = temp*nums[i]
            output[i] = temp
        
        #compute output by computing right at same time
        output[n-1] = output[n-2]
        temp = 1
        for i in range(n-2, 0, -1):
            temp = temp*nums[i+1]
            output[i] = output[i-1]*temp
        output[0] = nums[1]*temp
        
        return output
         
```