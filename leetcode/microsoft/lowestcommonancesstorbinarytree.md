```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def recTrav(self, root, p, q):
        if root == None:
            return False
        
        mid = False
        if root == p or root == q:
            mid = True
        
        left = self.recTrav(root.left, p, q)
        right = self.recTrav(root.right, p, q)
        
        if (left==True and right==True) or (left == True and mid == True) or (right == True and mid == True) :
            self.common = root
            return True
        
        return left or right or mid
        
        
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        self.common = None
        self.recTrav(root, p, q)
        return self.common
```

# Elegant Solution
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:        
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if root == p or root == q:
            return root
        
        left = right = None 

        if root.left:
            left = self.lowestCommonAncestor(root.left, p, q)
        if root.right:
            right = self.lowestCommonAncestor(root.right, p, q)
        

        if left and right:
            return root
        else:
            return left or right
```