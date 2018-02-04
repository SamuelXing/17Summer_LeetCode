# Definition for binary tree with next pointer.
# class TreeLinkNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#         self.next = None

class Solution:
    # @param root, a tree link node
    # @return nothing
    def connect(self, root):
        if root is None:
            return
        Q = [root]
        while len(Q):
            temp = []
            for i in range(len(Q)):
                if Q[i].left:
                    temp.append(Q[i].left)
                if Q[i].right:
                    temp.append(Q[i].right)
            for i in range(len(temp)):
                if i+1 < len(temp):
                    temp[i].next = temp[i+1]
                else:
                    temp[i].next = None
            Q = temp
        return
                
      