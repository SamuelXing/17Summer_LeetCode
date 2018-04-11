# Definition for singly-linked list with a random pointer.
# class RandomListNode(object):
#     def __init__(self, x):
#         self.label = x
#         self.next = None
#         self.random = None

class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: RandomListNode
        :rtype: RandomListNode
        """
        if head == None:
            return None
        
        hashMap = {}
        copyH = RandomListNode(head.label)
        hashMap[head] = copyH
        pHead, pCopy = head, copyH
        
        while pHead:
            pCopy.random = pHead.random
            if pHead.next:
                pCopy.next = RandomListNode(pHead.next.label)
                hashMap[pHead.next] = pCopy.next
            else:
                pCopy.next = None
            
            pHead = pHead.next
            pCopy = pCopy.next
            
        pCopy = copyH
        while pCopy:
            if pCopy.random:
                pCopy.random = hashMap[pCopy.random]
            pCopy = pCopy.next
        return copyH