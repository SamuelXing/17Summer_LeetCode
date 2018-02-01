# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        if not preorder:
            return None
        root = TreeNode(preorder[0])
        rootIdx = inorder.index(preorder[0])
        root.left = self.buildTree(preorder[1:rootIdx+1], inorder[:rootIdx])
        root.right = self.buildTree(preorder[rootIdx+1:], inorder[rootIdx+1:])
        return root
        
        