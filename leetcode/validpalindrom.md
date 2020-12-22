# My Solution
## 48 ms	14.6 MB
```
class Solution:
    def isPalindrome(self, s: str) -> bool:
        
        def isan(c):
            if (ord(c) >= ord('a') and ord(c) <= ord('z')) or (ord(c) >= ord('0') and ord(c) <= ord('9')) or (ord(c) >= ord('A') and ord(c) <= ord('Z')):
                return True
            else:
                return False
                
        
        n = len(s)
        if n == 0:
            return True
        
        i = 0
        j = n-1
        while i <= j:
            print(i,j)
            if not isan(s[i]):
                i += 1
                continue
                
            if not isan(s[j]):
                j -= 1
                continue
            
            if s[i].lower() != s[j].lower():
                return False
            
            i += 1
            j -= 1
        
        return True
```
# Low Timecomlexity Solution:
## 32 ms	20.1 MB
class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = [i.lower() for i in s if i.isalnum()]
        return s == s[::-1]

# Low memory Solution
## 88 ms	14.6 MB
```
class Solution:
    def isPalindrome(self, s: str) -> bool:
        #s = re.sub('([^\w]|[_])', '', s)
        start = 0
        end = len(s) - 1
        
        def is_correct(c):
            k = ord(c)
            is_numeric = 48 <= k <= 57
            is_lower_alpha = 97 <= k <= 122
            is_upper_alpha = 65 <= k <= 90
            return any([is_numeric, is_lower_alpha, is_upper_alpha])
        
        while start < end:
            if not is_correct(s[start]):
                start += 1
            elif not is_correct(s[end]):
                end -= 1
            # print(start, end)
            elif s[start].lower() != s[end].lower():
                print(s[start].lower(), s[end].lower())
                return False
            else:
                start += 1
                end -= 1
        return True
```