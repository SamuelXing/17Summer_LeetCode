# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rightSideView(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        rst = []
        
        def dfs(node, depth):
            if not node:
                return node
            
            if depth == len(rst):
                rst.append(node.val)
            
            dfs(node.right, depth+1)
            dfs(node.left, depth+1)
            
        dfs(root, 0)
        return rst