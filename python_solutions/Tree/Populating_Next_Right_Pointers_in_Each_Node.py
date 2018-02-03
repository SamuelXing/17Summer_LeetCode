# BFS
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
        prevLevel, curLevel = [root], [root]
        root.next = None
        if root.left == None and root.right is None:
            return
        while curLevel:
            if len(curLevel) == 1:
                curLevel = [root.left, root.right]
                continue
            temp = []
            for i in range(len(curLevel)):      
                if i%2 == 1:
                    if prevLevel[int(i/2)].next:
                        curLevel[i].next = prevLevel[int(i/2)].next.left
                    else:
                        curLevel[i].next = None
                else:
                    curLevel[i].next = prevLevel[int(i/2)].right
                if curLevel[i].left and curLevel[i].right:
                    temp.append(curLevel[i].left)
                    temp.append(curLevel[i].right)
            if len(temp) == 0:
                break
            prevLevel = curLevel
            curLevel = temp
        return
        
                
        
        