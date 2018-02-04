# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def getListLen(self, head):
        size = 0
        while head:
            head = head.next
            size+=1
        return size
    
    def sortedListToBST(self, head):
        """
        :type head: ListNode
        :rtype: TreeNode
        """
        if head is None:
            return None
        listLen = self.getListLen(head)
        return self.helper(head, listLen)

    def helper(self, head, listLen):
        if listLen == 0:
            return None
        curNode = TreeNode(0)
        curNode.left = self.helper(head, int(listLen/2))
        curNode.val = head.val
        head = head.next
        curNode.right = self.helper(head, listLen-int(listLen/2)-1)
        return curNode

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sortedListToBST(self, head):
        """
        :type head: ListNode
        :rtype: TreeNode
        """
        return self.build(head, None)

    def build(self, start, end):
        if start == end:
            return None
        slow, fast = start, start
        
        while fast != end and fast.next != end:
            slow = slow.next
            fast = fast.next.next
        
        root = TreeNode(slow.val)
        root.left = self.build(start, slow)
        root.right = self.build(slow.next, end)    
        return root
