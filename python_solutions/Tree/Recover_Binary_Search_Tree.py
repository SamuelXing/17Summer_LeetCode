# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    first = None
    second = None
    prev = None
    
    def traverse(self, root):
        if root is None:
            return
        self.traverse(root.left)
        if self.prev is None:
            self.prev = root
        else:
            if root.val <= self.prev.val:
                if self.first is None:
                    self.first = self.prev
                self.second = root
            self.prev = root
        self.traverse(root.right)
    
    def recoverTree(self, root):
        """
        :type root: TreeNode
        :rtype: void Do not return anything, modify root in-place instead.
        """
        self.traverse(root)
        tmp = self.first.val
        self.first.val = self.second.val
        self.second.val = tmp
        
            
        
        