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
        self.ret = []
        self.dfs(sorted(nums), [], 0)
        return self.ret

    def dfs(self, nums, temp, idx):
        self.ret.append([x for x in temp])
        
        for i in range(idx, len(nums)):
            temp.append(nums[i])
            self.dfs(nums, temp, idx+1)
            temp.pop()

            