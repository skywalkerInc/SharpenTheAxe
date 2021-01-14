```
from collections import defaultdict
class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        pwords = defaultdict(int)
        start = 0
        ptr = 0
        while ptr < len(paragraph):
            
            ch = paragraph[ptr]
            
            if not ch.isalpha():
                word = paragraph[start:ptr].lower()
                pwords[word] += 1
                
                #search for next alpha
                start = ptr + 1
                while start < len(paragraph) and not paragraph[start].isalpha():
                    start += 1
                ptr = start
            else:
                if ptr == len(paragraph) -1:
                    word = paragraph[start:ptr+1].lower()
                    pwords[word] += 1
                ptr += 1
         
        words = sorted([(key, pwords[key]) for key in pwords], key= lambda t: t[1], reverse=True )
        for word, freq in words:
            if word not in banned:
                return word
        return ""
                
                
```