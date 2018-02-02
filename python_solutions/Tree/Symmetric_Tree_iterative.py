# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if root is None:
            return True
        if root.left is None and root.right is None:
            return True
        if root.left is None or root.right is None:
            return False
        lq, rq = [root.left], [root.right]
        while len(lq) != 0 and len(rq) != 0:
            ln, rn = lq.pop(), rq.pop()
            if ln is None and rn is None:
                continue
            if ln is None or rn is None:
                return False
            if ln.val != rn.val:
                return False
            lq.insert(0, ln.left)
            lq.insert(0, ln.right)
            rq.insert(0, rn.right)
            rq.insert(0, rn.left)
        return True
                