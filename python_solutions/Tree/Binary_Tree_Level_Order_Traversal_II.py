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

# solution 2
class Solution:
    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if root is None:
            return []
        level = self.height(root)
        self.ret = [[] for i in range(level)]
        self.DFS(root, level-1, self.ret)
        return self.ret
        
    def DFS(self, node, level, ret):
        ret[level].append(node.val)
        if node.left:
            self.DFS(node.left, level-1, ret)
        if node.right:
            self.DFS(node.right, level-1, ret)
    
    def height(self, root):
        if root is None:
            return 0
        return max(self.height(root.left), self.height(root.right)) + 1

