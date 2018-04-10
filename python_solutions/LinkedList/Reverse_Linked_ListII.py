class Solution:
    def reverseBetween(self, head, m, n):
        """
        :type head: ListNode
        :type m: int
        :type n: int
        :rtype: ListNode
        """
        if head is None:
            return None
        
        pPrev, pCur = ListNode(-1), head
        pPrev.next, dummy = pCur, pPrev
       
        
        # find start point
        it = 1
        while it < m:
            it += 1
            pPrev, pCur = pPrev.next, pCur.next
        
        while it < n:
            pNext = pCur.next
            pCur.next = pNext.next
            pNext.next = pPrev.next
            pPrev.next = pNext
            it +=1
        
        return dummy.next
        
    