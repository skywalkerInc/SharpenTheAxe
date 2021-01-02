```
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if digits == "":
            return []
        
        keymap = {}
        keymap['1'] = []
        keymap['2'] = ['a','b','c']
        keymap['3'] = ['d', 'e', 'f']
        keymap['4'] = ['g', 'h', 'i']
        keymap['5'] = ['j', 'k', 'l']
        keymap['6'] = ['m', 'n', 'o']
        keymap['7'] = ['p', 'q', 'r', 's']
        keymap['8'] = ['t', 'u', 'v']
        keymap['9'] = ['w', 'x', 'y', 'z']
        keymap['0'] = [' ']
        
        
        res = ['']
        for digit in digits:
            temp = []
            for letter in keymap[digit]:
                for word in res:
                    temp.append(word + letter)
            res = [word for word in temp]
        return res
```

## Recursive Solution
```
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if digits == "":
            return []
        
        keymap = {}
        keymap['1'] = []
        keymap['2'] = ['a','b','c']
        keymap['3'] = ['d', 'e', 'f']
        keymap['4'] = ['g', 'h', 'i']
        keymap['5'] = ['j', 'k', 'l']
        keymap['6'] = ['m', 'n', 'o']
        keymap['7'] = ['p', 'q', 'r', 's']
        keymap['8'] = ['t', 'u', 'v']
        keymap['9'] = ['w', 'x', 'y', 'z']
        keymap['0'] = [' ']
        
        
        def backtrack(combination, digits):
            if len(digits) == 0:
                output.append(combination)
            else:
                for letter in keymap[digits[0]]:
                    backtrack(combination + letter, digits[1:])
        
        output = []
        if digits:
            backtrack("", digits)
        
        return output
```