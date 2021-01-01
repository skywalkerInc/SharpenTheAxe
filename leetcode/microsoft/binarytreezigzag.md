# first solution
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        if root == None:
            return []
        
        res = []
        
        fq = deque([])
        bq = deque([])
        
        fq.append(root)
        toggle = 0
        while fq or bq:
            temp = []
            if toggle == 0:
                
                while fq:
                    node = fq.popleft()
                    if node != None:
                        bq.append(node.left)
                        bq.append(node.right)
                        temp.append(node.val)
                if len(temp) > 0:
                    res.append([num for num in temp])
                toggle = 1
            elif toggle == 1:
                while bq:
                    node = bq.popleft()
                    if node != None:
                        fq.append(node.left)
                        fq.append(node.right)
                        temp.append(node.val)
                if len(temp) > 0:
                    res.append([num for num in temp[::-1]])
                toggle = 0
        return res
        
        
```
