# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def verticalOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        
        # group the node with the same cols, how? bfs, using queue
        hashMap = collections.defaultdict(list)
        queue = [(root, 0)]
        
        for node, i in queue:
            if node:
                hashMap[i].append(node.val)
                queue += [(node.left, i-1), (node.right, i+1)]
        
        # sorted(hashMap) make hash map sorted by (key)
        return [hashMap[i] for i in sorted(hashMap)]