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
        if head is None:
            return head
        
        pNode = head
        while pNode and pNode.next:
            if pNode.val == pNode.next.val:
                pNode.next = pNode.next.next
            else:
                pNode = pNode.next
            
        return head