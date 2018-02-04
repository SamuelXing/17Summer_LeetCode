# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sortedArrayToBST(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        return self.build(nums, 0, len(nums))
    
    def build(self, nums, start, end):
        if start == end:
            return None
        
        mid = start + int((end-start)/2)
        root = TreeNode(nums[mid])
        root.left = self.build(nums, start, mid)
        root.right = self.build(nums, mid+1, end)
        return root
        