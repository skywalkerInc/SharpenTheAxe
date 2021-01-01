# O(n) S(n)
```
"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""
from collections import deque
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if root == None:
            return None
        
        q = deque([])
        q.append(root)
        
        while q:
            
            curr = [node for node in q]
            q = deque([])
            prev = curr[0]
            for node in curr[1:]:
                prev.next = node
                prev = node
            prev.next = None
            
            for node in curr:
                if node.left != None:
                    q.append(node.left)
                if node.right != None:
                    q.append(node.right)
            
            
        return root
```

# O(n) S(1)
```
from collections import deque
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if root == None:
            return None
        
        leftmost = root
        while leftmost.left:
            head = leftmost
            while head:
                head.left.next = head.right
                if head.next:
                    head.right.next = head.next.left
                head = head.next
            leftmost = leftmost.left
        return root
```
