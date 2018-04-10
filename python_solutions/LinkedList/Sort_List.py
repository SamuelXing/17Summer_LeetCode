# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def sortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        
        if head is None or head.next is None:
            return head
        
        slow, fast = head, head
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
        
        fast = slow.next
        slow.next = None

        left  = self.sortList(head)
        right = self.sortList(fast)
        
        return self.Merge(left, right)
    
    def Merge(self, l1, l2):
        if l1 is None:
            return l2
        if l2 is None:
            return l1
        if not l1 and not l2:
            return None
        
        pPtr = ListNode(0)
        Dummy = pPtr
        while l1 and l2:
            if l1.val <= l2.val:
                pPtr.next = l1
                l1 = l1.next
            else:
                pPtr.next = l2
                l2 = l2.next
            pPtr = pPtr.next
        if l1 is not None:
            pPtr.next = l1
        else:
            pPtr.next = l2
        return Dummy.next