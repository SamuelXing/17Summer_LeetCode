# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        if n == 0:
            return []
        return self.dfs(1, n)
    
    def dfs(self, start, end):
        if start > end:
            return [None]
        ret = []
        for rootval in range(start, end+1):
            leftTree = self.dfs(start, rootval-1)
            rightTree = self.dfs(rootval+1, end)
            for i in leftTree:
                for j in rightTree:
                    root = TreeNode(rootval)
                    root.left = i
                    root.right = j
                    ret.append(root)
        return ret
