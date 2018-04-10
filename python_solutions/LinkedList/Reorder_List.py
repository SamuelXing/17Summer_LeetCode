# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reorderList(self, head):
        """
        :type head: ListNode
        :rtype: void Do not return anything, modify head in-place instead.
        """
        if head is None or head.next is None:
            return
        
        slow, fast = head, head
        while fast.next and fast.next.next:
            fast = fast.next.next
            slow = slow.next
        
        fast = slow.next
        slow.next = None
        
        # reverse fast
        pCur = None
        while fast != None:
            temp = fast.next
            fast.next = pCur
            pCur = fast
            fast = temp
        
        # Merge 
        tail = head
        while pCur:
            pNext = pCur.next
            pCur.next = tail.next
            tail.next = pCur
            tail = tail.next.next
            pCur = pNext
        
    