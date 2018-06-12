# must sort!
# keep tha array in ascending orderm when the curSum is greater than the target, no need to conut any more
class Solution:
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        candidates.sort()
        self.ret = []
        self.dfs(candidates, target, 0, [])
        return self.ret
    
    def dfs(self, candidates, target, start, temp):
        if target == 0:
            self.ret.append(temp)
            return
        else:
            for i in range(start, len(candidates)):
                if target < candidates[i]:
                    return
                self.dfs(candidates, target - candidates[i], i, temp+[candidates[i]])
        