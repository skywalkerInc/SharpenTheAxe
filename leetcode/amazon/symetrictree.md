```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def helper(self, lroot, rroot):
        if not lroot and not rroot:
            return True
        elif not lroot:
            return False
        elif not rroot:
            return False
        
        if lroot.val != rroot.val:
            return False
        
        
        return self.helper(lroot.right, rroot.left) and self.helper(lroot.left, rroot.right)
        
        
        
    def isSymmetric(self, root: TreeNode) -> bool:
        if not root:
            return True
        
        return self.helper(root.left, root.right)
```