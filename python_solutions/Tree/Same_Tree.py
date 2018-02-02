# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        if q is None and p is None:
            return True
        if p is None or q is None:
            return False
        return (p.val == q.val) and self.isSameTree(q.left, p.left) and self.isSameTree(q.right, p.right);