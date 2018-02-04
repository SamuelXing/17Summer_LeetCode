# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """
        self.rst = []
        self.path = ""
        self.helper(root, self.rst, self.path)
        return self.rst
    
    def helper(self, root, rst, path):
        if root is None:
            return
        if root.left is None and root.right is None:
            path += str(root.val)
            rst.append(path)
            path = ""
        path += str(root.val) + "->"
        self.helper(root.left, rst, path)
        self.helper(root.right, rst, path)