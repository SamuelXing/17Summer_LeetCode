# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        # edge cases
        if l1 is None and l2 is None:
            return None
        elif l1 is None:
            return l2
        elif l2 is None:
            return l1
        
        # using stacks
        stack1, stack2 = [], []
        
        # push in
        while l1 is not None:
            stack1.append(l1.val)
            l1 = l1.next

        while l2 is not None:
            stack2.append(l2.val)
            l2 = l2.next
        
        # pop out
        head, carry = None, 0
        while stack1 or stack2:
            s = 0
            if stack1: s += stack1.pop()
            if stack2: s += stack2.pop()
            newHead = ListNode((s+carry)%10)
            carry = (s+carry) // 10
            newHead.next = head
            head = newHead
            
        # check carry
        while carry:
            newHead = ListNode(carry % 10)
            carry = carry // 10
            newHead.next = head
            head = newHead
        
        return head
    
        
            
        