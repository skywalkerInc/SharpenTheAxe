

## 30mins (BST)
``` py


class TreeNode:
    
    def __init__(self, start, end):
        self.start = start
        self.end = end
        self.left = None
        self.right = None

class MyCalendar:

    def __init__(self):
        self.root = None
        
    def searchNode(self, node, root):
        if not root:
            return False
        
        if (node.start < root.end and node.end > root.start):
            return True
        
        if (node.end <= root.start):
            return self.searchNode(node, root.left)
        elif (node.start >= root.end):
            return self.searchNode(node, root.right)
        
        return True
    
    def appendNode(self, node, root):
        if not root:
            return node
        
        if(node.end <= root.start):
            root.left = self.appendNode(node, root.left)
        elif (node.start >= root.end):
            root.right = self.appendNode(node, root.right)
            
        return root
    
    def printTree(self, root):
        
        if not root:
            return
        
        self.printTree(root.left)
        print("[ {}, {} ]".format(root.start, root.end))
        self.printTree(root.right)
        
    
    def book(self, start: int, end: int) -> bool:
        ret = True
        
        newTreeNode = TreeNode(start, end)
        
        # end < start should go to left 
        # start >= end should go to right
        
        if self.root == None:
            self.root = newTreeNode
            return True
        
        # print("node: [ {}, {} ]".format(start, end))
        # self.printTree(self.root)
        
        intervalFound = self.searchNode(newTreeNode, self.root)
        # print(intervalFound)
        if not intervalFound:
            self.appendNode(newTreeNode, self.root)
        
        return not intervalFound


# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)
```

## 20mins (Brute force solution) O(n2)
``` c++

class MyCalendar:

    def __init__(self):
        self.intervals = []
    
    def isClashing(self, interval1, interval2):
        if ((interval1[0] < interval2[0] and interval1[1] > interval2[0]) or
            (interval1[0] >= interval2[0] and interval1[0] < interval2[1])):
            return True
        
        return False
            
    
    def book(self, start: int, end: int) -> bool:
        newInterval = (start, end)
        ret = True
        for interval in self.intervals:
            if(self.isClashing(interval, newInterval)):
                ret = False 
        
        if ret:
            self.intervals.append(newInterval)
        
        return ret


# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)
```