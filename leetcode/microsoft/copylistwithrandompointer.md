## with help of has O(n) S(n)
```

# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random


class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        
        has = {} #old vs new
        has[None] = None
        
        curr = head
        while curr:
            newnode = Node(curr.val)
            has[curr] = newnode
            curr = curr.next
        
        newhead = has[head]
        curr = head
        while curr:
            newnode = has[curr]
            newnode.next = has[curr.next]
            newnode.random = has[curr.random]
            curr = curr.next
        return newhead
        
        
```

## with weaving for lists S(1)
```

# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random


class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        
        if not head:
            return head
        
        #interweave
        curr = head
        while curr:
            newnode = Node(curr.val)
            newnode.next = curr.next
            curr.next = newnode
            curr = newnode.next
        
        #reference random pointer
        curr = head
        while curr:
            curr.next.random = curr.random.next if curr.random else None
            curr = curr.next.next
        
        #deweaving
        curr = head
        newhead = head.next
        currnew = newhead
        while curr:
            newnode = curr.next
            curr.next = curr.next.next
            currnew.next = currnew.next.next if currnew.next else None
            curr = curr.next
            currnew = currnew.next
        
        return newhead
        
```