# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        return self.findMin(root)
    
    def findMin(self, node):
        if node is None:
            return 0
        if node.left is None and node.right is None:
            return 1
        left, right = sys.maxsize, sys.maxsize 
        if node.left:
            left = self.findMin(node.left)
        if node.right:
            right = self.findMin(node.right)
        
        return min(left, right)+1
        