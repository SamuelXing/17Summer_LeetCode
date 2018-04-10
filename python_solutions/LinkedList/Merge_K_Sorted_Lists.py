from heapq import heappush, heappop
class Solution:
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        if lists is None:
            return None
        
        pHead = ListNode(-1)
        pCur = pHead
        heap = []
        for ln in lists:
            if ln:
                self.pushHeap(heap, ln)
        
        while pCur:
            curNode = heappop(heap)[1]
            pCur.next = curNode
            pCur = pCur.next
            if pCur.next:
                self.pushHead(heap, pCur.next)
        return pHead.next
                
    
    
    def pushHeap(self, heap, node):
        heappush(heap, (node.val, node))


# divide and conquer
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        if not len(lists):
            return None
        return self.MergeHelper(lists, 0, len(lists)-1)
    
    def MergeHelper(self, lists, start, end):
        if start == end:
            return lists[start]
        mid = start + int((end - start)/2)
        left = self.MergeHelper(lists, start, mid)
        right = self.MergeHelper(lists, mid+1, end)
        return self.MergeTwoLists(left, right)
    
    def MergeTwoLists(self, l1, l2):
        if not l1:
            return l2
        if not l2:
            return l1
        
        pHead = ListNode(-1)
        pCur = pHead
        while l1 and l2:
            if l1.val <= l2.val:
                pCur.next = l1
                l1 = l1.next
            else:
                pCur.next = l2
                l2 = l2.next
            pCur = pCur.next
        if l1 is not None:
            pCur.next = l1
        else:
            pCur.next = l2
        
        return pHead.next

               