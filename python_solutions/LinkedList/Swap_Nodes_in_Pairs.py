# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        pPrev, pCur = ListNode(0), head
        pPrev.next, dummy= head, pPrev
        
        while pCur:
            if pCur.next is None:
                return dummy.next
            # reverse
            pNext = pCur.next
            pCur.next = pNext.next
            pNext.next = pPrev.next
            pPrev.next = pNext
            
            pPrev = pPrev.next.next
            pCur = pPrev.next
            
        return dummy.next
