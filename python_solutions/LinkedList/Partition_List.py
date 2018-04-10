# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        if head is None:
            return head
  
        ll, lg = ListNode(0), ListNode(0)
        pll, plg = ll, lg
        while head:
            if head.val < x:
                pll.next = head
                pll = pll.next
            else:
                plg.next = head
                plg = plg.next
            head = head.next
        
        plg.next = None
        pll.next = lg.next
        return ll.next
        