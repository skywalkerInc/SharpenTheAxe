## has solution O(m+n) S(m+n)
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        
        has = {}
        while headA or headB:
            
            if headA:
                if headA in has:
                    return headA
                else:
                    has[headA] = 1
                headA = headA.next
            
            if headB:
                if headB in has:
                    return headB
                else:
                    has[headB] = 1
                headB = headB.next
            
        return None
            
            
```

# two pointer solution
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        
        p1, p2 = headA, headB
        
        while p1 != p2:
            
            if p1:
                p1 = p1.next
            else:
                p1 = headB
                
            if p2:
                p2 = p2.next
            else:
                p2 = headA
        
        return p1
```