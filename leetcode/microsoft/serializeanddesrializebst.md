```


class Codec:
    # Definition for a binary tree node.
    class TreeNode:
        def __init__(self, x):
            self.val = x
            self.left = None
            self.right = None
    
    def int_to_str(self, x):
        bytearr = [chr(x >> (i*8) & 0xff) for i in range(4)]
        return ''.join(bytearr[::-1]) 
        
    def serialize(self, root: TreeNode) -> str:
        """Encodes a tree to a single string.
        """
        out = []
        
        def preorder(node, out):
            if not node:
                return out
            
            out.append(node.val)
            out = preorder(node.left, out)
            out = preorder(node.right, out)
            
            return out
            
        
        out = preorder(root, out)
        out = [self.int_to_str(x) for x in out]
        
        return ''.join(out)
    
    def str_to_int(self, bytes_str):
        result = 0
        for ch in bytes_str:
            result = result * 256 + ord(ch)
        return result

    def deserialize(self, data: str) -> TreeNode:
        """Decodes your encoded data to tree.
        """
        if len(data) == 0:
            return None
        
        def gentree_preorder(low = float('-inf'), high = float('inf')):
            if not data or data[0] < low or data[0] > high:
                return None
            
            val = data.pop(0)
            root = TreeNode(val)
            root.left = gentree_preorder(low, val)
            root.right = gentree_preorder(val, high)
            
            return root
            
            
        data = [self.str_to_int(data[4*i:4*i + 4]) for i in range(len(data)//4)]
        
        return gentree_preorder()

# Your Codec object will be instantiated and called as such:
# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# tree = ser.serialize(root)
# ans = deser.deserialize(tree)
# return ans
```