```
"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""
from collections import deque
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []

class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if not node:
            return node
        
        q = deque([])
        has = {}
  
        has[node] = Node(node.val, [])
        q.append(node)
        
        while q:
            oldnode = q.popleft()
            for nbh in oldnode.neighbors:
                if nbh not in has:
                    has[nbh] = Node(nbh.val)
                    q.append(nbh)
                has[oldnode].neighbors.append(has[nbh])
                

        return has[node]
        
        
        
```