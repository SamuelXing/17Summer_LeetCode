# recursive solution
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        rst = []
        self.traverse(root, rst)
        return rst
    
    def traverse(self, node, rst):
        if node is None:
            return
        self.traverse(node.left, rst)
        rst.append(node.val)
        self.traverse(node.right, rst)


# iterative solution
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        rst, stack = [], []
        curNode = root
        while len(stack) or curNode:
            while curNode is not None:
                stack.append(curNode)
                curNode = curNode.left
            
            curNode = stack.pop()
            rst.append(curNode.val)
            curNode = curNode.right
        return rst
              
        
        
