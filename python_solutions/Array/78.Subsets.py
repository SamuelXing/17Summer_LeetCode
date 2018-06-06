# # DFS 1
# class Solution:
#     def subsets(self, nums):
#         """
#         :type nums: List[int]
#         :rtype: List[List[int]]
#         """
#         self.ret = []
#         self.dfs(sorted(nums), [], 0)
#         return self.ret
    
#     def dfs(self, nums, temp, idx):
#         if idx == len(nums):
#             self.ret.append(temp)
#             return
        
#         self.dfs(nums, temp+[nums[idx]], idx+1);
#         self.dfs(nums, temp, idx+1)


class Solution:
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        ret, temp = [], []
        self.dfs(sorted(nums), ret, temp, 0)
        return ret
    
    def dfs(self, nums, ret, temp, start):
        ret.append(temp)
        
        for i in range(start, len(nums)):
            temp.append(nums[i])
            self.dfs(nums, ret, temp, i+1)
            temp.pop()

            