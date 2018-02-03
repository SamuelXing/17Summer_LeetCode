# recursive
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def postorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        rst = []
        self.traverse(root, rst)
        return rst
    
    def traverse(self, node, rst):
        if node is None:
            return rst
        self.traverse(node.left, rst)
        self.traverse(node.right, rst)
        rst.append(node.val)


# iterative
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def postorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        rst, stack =[], []
        curNode, curRoot = root, None
        if root is None:
            return rst
        while len(stack) or curNode:
            while curNode:
                stack.append(curNode)
                curNode = curNode.left
            curNode = stack[-1]
            if curNode.right is None or curNode.right == curRoot:
                node = stack.pop()
                rst.append(node.val)
                curRoot = curNode
                curNode = None
            else:
                curNode = curNode.right
        
        return rst