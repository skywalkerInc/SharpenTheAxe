```
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        out = ''
        def helper(root, out):
            if root == None:
                out += 'None,'
            else:
                out += str(root.val) + ','
                out = helper(root.left, out)
                out = helper(root.right, out)
            return out
        return helper(root, '')

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        def helper(arr):
            if arr[0] == 'None':
                arr.pop(0)
                return None
            
            root = TreeNode(arr[0])
            arr.pop(0)
            root.left = helper(arr)
            root.right = helper(arr)
            return root
        
        root = helper(data.split(','))
        return root
        

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))
```