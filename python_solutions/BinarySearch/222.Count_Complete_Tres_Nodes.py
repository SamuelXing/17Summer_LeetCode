# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# recursive version
class Solution:
    def countNodes(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return 0
        
        lHeight, rHeight = self.height(root.left), self.height(root.right)
        if lHeight == rHeight:
            return 2**lHeight + self.countNodes(root.right)
        else:
            return 2**rHeight + self.countNodes(root.left)
            
    
    def height(self, root):
        return 0 if root is None else 1 + self.height(root.left)

# iterative version
class Solution:
    def countNodes(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        ret = 0
        while root:
            lh, lr = self.height(root.left), self.height(root.right)
            if lh == lr:
                ret += 1 << lh
                root = root.right
            elif lh > lr:
                ret += 1 << lr
                root = root.left
        return ret
    
    def height(self, root):
        return 0 if root is None else 1 + self.height(root.left)