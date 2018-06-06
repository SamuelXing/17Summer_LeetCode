class Solution:
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        self.ret = []
        self.dfs(sorted(nums), [], 0)
        return self.ret
    
    def dfs(self, nums, temp, idx):
        if idx == len(nums):
            if temp not in self.ret:
                self.ret.append(temp)
            return
        
        self.dfs(nums, temp, idx+1)
        self.dfs(nums, temp+[nums[idx]], idx+1);