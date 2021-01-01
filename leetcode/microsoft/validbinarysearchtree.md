# My solution
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def recIsValidBST(self, root, lmin, lmax):
        
        if root == None:
            return True
        
        if root.val <= lmin or root.val >= lmax:
            return False
        
        left = self.recIsValidBST(root.left, lmin, root.val)
        right = self.recIsValidBST(root.right, root.val, lmax)
        
        return left and right
        
        
    def isValidBST(self, root: TreeNode) -> bool:
        
        return self.recIsValidBST(root, float('-inf'), float('inf'))
        
        
```

# Inorder traversal solution
```
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        
        def inorder(root):
            if not root:
                return True
            if not inorder(root.left):
                return False
            if root.val <= self.prev:
                return False
            self.prev = root.val
            return inorder(root.right)
        
        self.prev = -math.inf
        return inorder(root)
```