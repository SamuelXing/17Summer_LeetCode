# recursive
class Solution:
    def kthSmallest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        self.count = []
        self.helper(root)
        return self.count[k-1]

    def helper(self, root):
        if root is None:
            return
        
        self.helper(root.left)
        self.count.append(root.val)
        self.helper(root.right)


# Iterative -stack
class Solution:
    def kthSmallest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        
        count, p = 0, root
        stack = []
        
        while stack or p:
            if p:
                stack.append(p)
                p = p.left
            else:
                node = stack.pop()
                count += 1
                if count == k: return node.val
                p = node.right
        
        return sys.maxsize