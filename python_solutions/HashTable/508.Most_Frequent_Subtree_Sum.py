# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findFrequentTreeSum(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if root is None:
            return []
        frequency = collections.defaultdict(int)
        
        def dfs(root):
            if root is None:
                return 0
            s = root.val + dfs(root.left) + dfs(root.right)
            frequency[s] += 1
            return s
        
        dfs(root)
        maxFrequency = max(frequency.values())
        return list(filter(lambda s: frequency[s] == maxFrequency, frequency.keys()))