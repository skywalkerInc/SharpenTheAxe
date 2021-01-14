```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        
        def rec(node):
            nonlocal maxsum
            
            if not node:
                return 0
            
            #check left and right path maxsum
            left = max(rec(node.left), 0) #to avoid negative 
            right = max(rec(node.right), 0)
            
            rootpath = node.val + left + right
            maxsum = max(maxsum, rootpath)
            
            return max(left, right) + node.val
            
        maxsum = float('-inf')
        ret = rec(root)
        return maxsum
            
```