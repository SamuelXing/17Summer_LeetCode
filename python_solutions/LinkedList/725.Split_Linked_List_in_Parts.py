# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def splitListToParts(self, root, k):
        """
        :type root: ListNode
        :type k: int
        :rtype: List[ListNode]
        """
        # count length
        p, length = root, 0
        while p:
            p, length = p.next, length + 1
        
        chunks, diff = length//k, length%k
        
        # mark the size of each chunk
        marks = [chunks+1]*diff + [chunks]*(k-diff)
        
        # split up list
        prev, cur = None, root
        for i, m in enumerate(marks):
            if prev:
                prev.next = None
            marks[i] = cur
            for i in range(m):
                prev, cur = cur, cur.next
        
        return marks
            