```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def recInorder(self, root):
        if root == None:
            return 
        
        self.recInorder(root.left)
        self.res.append(root.val)
        self.recInorder(root.right)
        
        return 
        
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        self.res = []
        self.recInorder(root)
        return self.res
```