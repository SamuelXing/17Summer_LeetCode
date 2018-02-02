# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if root is None:
            return True
        return self.check(root.left, root.right)
    
    def check(self, left, right):
        if left is None and right is None:
            return True
        if left is None or right is None:
            return False
        cond1 = left.val == right.val
        cond2 = self.check(left.left, right.right)
        cond3 = self.check(left.right, right.left)
        return cond1 and cond2 and cond3


        
        