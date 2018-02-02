# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        self.ret = []
        if root is None:
            return self.ret
        Q = [root]
        while Q:
            self.ret.append([n.val for n in Q])
            newQ = []
            for node in Q:
                if node.left:
                    newQ.append(node.left)
                if node.right:
                    newQ.append(node.right)
            Q = newQ
        return list(reversed(self.ret))