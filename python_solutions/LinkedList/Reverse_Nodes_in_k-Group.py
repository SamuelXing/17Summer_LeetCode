# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if head is None:
            return None
        
        pPrev = ListNode(-1)
        pPrev.next, pPtr, dummy = head, pPrev, pPrev
        
        while pPtr is not None:
            pPrev = pPtr
            for i in range(k):
                pPtr = pPtr.next
                if pPtr is None:
                    return dummy.next
            pPtr = self.reverse(pPrev, pPtr.next)
            
        return dummy.next
    
    def reverse(self, pPrev, pEnd):
        pCur = pPrev.next
        while pCur.next != pEnd:
                pNext = pCur.next
                pCur.next = pNext.next
                pNext.next = pPrev.next
                pPrev.next = pNext
        return pCur
        
            
        