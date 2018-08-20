# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    maxVal = 0
    def longestConsecutive(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        self.dfs(root, 0, root.val)
        return self.maxVal
        
    def dfs(self, root, cur, target):
        if not root:
            return
        cur = cur + 1 if root.val == target else 1
        self.maxVal = max(self.maxVal, cur)
        self.dfs(root.left, cur, root.val + 1)
        self.dfs(root.right, cur, root.val + 1)