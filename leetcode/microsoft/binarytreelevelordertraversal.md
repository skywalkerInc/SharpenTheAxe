```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        res = []
        q = deque([])
        q.append((root, 0))
        while q:
            node, level  = q.popleft()
            
            if node != None:
                q.append((node.left, level + 1))
                q.append((node.right, level + 1))
                #print(node.val, level, res)
            
                if len(res) <= level:
                    res.append([])

                res[level].append(node.val)
        return res
            
```