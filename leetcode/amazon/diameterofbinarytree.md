```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        
        def dia(node):
            nonlocal maxpath
            if not node:
                return 0
            
            left = dia(node.left)
            right = dia(node.right)
            
            rootpath = left + right
            maxpath = max(maxpath, rootpath)
            
            return max(left, right) + 1
        
        maxpath = 0
        ret = dia(root)
        return maxpath
```