# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        return self.helper(root, -sys.maxsize-1, sys.maxsize)
    
    def helper(self, root, minval, maxval):
        if root is None:
            return True
        
        if root.val <= minval or root.val >= maxval:
            return False
        
        return self.helper(root.left, minval, root.val) and self.helper(root.right, root.val, maxval)