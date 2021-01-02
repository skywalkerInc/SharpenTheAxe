
## PriorityQ/Heap O(Nlogk) O(k) Runs on python (not python3)
```
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        q = []
        heapq.heapify(q)
        for node in lists:
            if node:
                heapq.heappush(q, (node.val, node))
        
        
        head = curr = ListNode()
        while q:
            val, node = heapq.heappop(q)
            curr.next = node
            curr = curr.next
            node = node.next
            if node:
                heapq.heappush(q, (node.val, node))
        return head.next
```
## Divide and Conquere O(Nlogk) S(1)
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        if not lists: 
            return None
        if len(lists) == 1: 
            return lists[0]
        mid = len(lists)//2 
        left = self.mergeKLists(lists[:mid])
        right = self.mergeKLists(lists[mid:])
        return self.merge_two_lists(left, right)
        
    def merge_two_lists(self, list1, list2): 
        dummy = pointer = ListNode(0)
        while list1 and list2: 
            if list1.val < list2.val: 
                pointer.next = list1
                list1 = list1.next 
            else:
                pointer.next = list2 
                list2 = list2.next 
            pointer = pointer.next 
        pointer.next = list1 or list2 
        return dummy.next 
```