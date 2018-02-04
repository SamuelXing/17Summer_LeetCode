# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
    
class Solution:
    
    total = 0
    
    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.helper(root, 0)
        return self.total
    
    def helper(self, root, path):
        if root is None:
            return
        path = path*10 + root.val
        if root.left is None and root.right is None:
            self.total += path
        self.helper(root.left, path)
        self.helper(root.right, path)