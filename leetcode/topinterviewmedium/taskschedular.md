```
from collections import defaultdict
class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        #total slots = busy slots + idle slots
        #busy slots = len(tasks)
        #calculate idle slots
        
        frequencies = [0]*26
        for task in tasks:
            frequencies[ord(task) - ord('A')] += 1
        
        fmax = max(frequencies)
        nmax = frequencies.count(fmax)
        
        return max(len(tasks), (fmax-1)*(n+1) + nmax)
        
                    
```

```
from collections import defaultdict
class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        #total slots = busy slots + idle slots
        #busy slots = len(tasks)
        #calculate idle slots
        
        frequencies = [0]*26
        for task in tasks:
            frequencies[ord(task) - ord('A')] += 1
        
        frequencies.sort()
        fmax = frequencies.pop()
        idletime = (fmax-1)*n
        
        while frequencies and idletime>0:
            idletime -= min(fmax-1, frequencies.pop())
        idletime = max(0, idletime)
        return idletime + len(tasks)
        
                    
```