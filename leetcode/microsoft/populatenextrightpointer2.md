# O(N) S(1)
```
class Solution:
    def processChild(self, node, prev, leftmost):
        if node:
            if prev:
                prev.next = node
            else:
                leftmost = node
            prev = node
        return prev, leftmost
        
        
    def connect(self, root: 'Node') -> 'Node':
        if root == None:
            return None
        
        leftmost = root
        while leftmost:
            prev, curr = None, leftmost
            leftmost = None
            while curr:
                prev, leftmost = self.processChild(curr.left, prev, leftmost)
                prev, leftmost = self.processChild(curr.right, prev, leftmost)
                curr = curr.next
        return root
```