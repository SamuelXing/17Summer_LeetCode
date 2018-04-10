# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if l1 is None:
            return l2
        if l2 is None:
            return l1
        pHead = ListNode(-1)
        pCur = pHead
        while l1 != None and l2 != None:
            if l1.val <= l2.val:
                pCur.next = l1
                l1 = l1.next
            else:
                pCur.next = l2
                l2 = l2.next
            pCur = pCur.next
        if l1 != None:
            pCur.next = l1
        else:
            pCur.next = l2
        return pHead.next