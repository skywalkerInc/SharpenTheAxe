
# My solution
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        
        num1 = float('inf')
        if l1:
            num1 = l1.val

        num2 = float('inf')
        if l2:
            num2 = l2.val
        
        head = None
        if num1 <= num2:
            head = l1
        else:
            head = l2
            
        while l1 or l2:
            num1 = float('inf')
            if l1:
                num1 = l1.val
            
            num2 = float('inf')
            if l2:
                num2 = l2.val

            if num1 <= num2:
                temp = l1.next
                if l2 and ((l1.next and l2.val < l1.next.val) or not l1.next):
                    l1.next = l2
                l1 = temp
            else:
                temp = l2.next
                if l1 and ((l2.next and l1.val <= l2.next.val) or not l2.next):
                    l2.next = l1
                l2 = temp
        
                
        return head    
```
## good solution
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        localList = ListNode()
        head = localList
        
        while l1 and l2:
            if l1 and l2 and l1.val <= l2.val:
                head.next = l1
                l1 = l1.next
            elif l1 and l2 and l2.val <= l1.val:
                head.next = l2
                l2 = l2.next
            head = head.next
            
        head.next = l1 or l2
            
        return localList.next
```