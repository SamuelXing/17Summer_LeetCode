# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None or head.next is None:
            return head
        # pHead, pPrev -> [1,2,3,3,4,4,5]
        pPrev, pNode = ListNode(-1), head
        pPrev.next, pHead = pNode, pPrev
        while pNode and pNode.next:
            if pNode.val == pNode.next.val:
                val = pNode.val
                while pNode and val == pNode.val:
                    pNode = pNode.next
                pPrev.next = pNode
            else:
                pNode = pNode.next
                pPrev = pPrev.next
        return pHead.next