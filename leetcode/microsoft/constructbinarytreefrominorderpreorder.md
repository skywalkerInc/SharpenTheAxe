```
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:

    def recSol(self, inleft, inright):
        if inleft == inright:
            return None
        
        rootval = self.preorder[self.preindex]
        root = TreeNode(rootval)
        index = self.idx_map[rootval]
        self.preindex += 1
        
        root.left = self.recSol(inleft, index)
        root.right = self.recSol(index+1, inright)
        
        
        return root
    
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        self.idx_map = {val:idx for idx, val in enumerate(inorder)}
        self.preindex = 0
        self.preorder = preorder
        return self.recSol(0, len(inorder))
        
```
## TLE
```
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def getPos(self, arr, target):
        for i, node in enumerate(arr):
            if node == target:
                return i
        return -1
        
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if len(preorder) == 0:
            return None
        
        root = TreeNode(preorder[0])
        
        rootpos_inorder = self.getPos(inorder, root.val)
        leftlen = rootpos_inorder
        rightlen = len(inorder) - rootpos_inorder - 1
        
        root.left = self.buildTree(preorder[1:leftlen + 1], inorder[0:leftlen])
        root.right = self.buildTree(preorder[leftlen+1:len(preorder)], inorder[leftlen+1:len(inorder)])
        
        return root
        
```