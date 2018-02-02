# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """
        self.ret = []
        self.solution = []
        
        self.findPath(self.ret, self.solution, root, sum)
        return self.ret
    
    def findPath(self, ret, solution, root, sum):
        if root is None:
            return
        sum = sum - root.val
        if root.left is None and root.right is None:
            if sum == 0:
                solution.append(root.val)
                ret.append(list(solution))
                solution.pop(-1)
            return
        solution.append(root.val)
        self.findPath(ret, solution, root.left, sum)
        self.findPath(ret, solution, root.right, sum)
        solution.pop(-1)
                
        