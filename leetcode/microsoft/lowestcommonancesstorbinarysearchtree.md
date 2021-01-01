```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
import bisect
class Solution:
 
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        pval = p.val
        qval = q.val
        node = root
        while node:
           
            if pval < node.val and qval < node.val:
                node = node.left
            elif pval > node.val and qval > node.val:
                node = node.right
            else:
                return node
                
            
        
```