class Solution:
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        
        self.ret = []
        self.dfs(sorted(candidates), [], 0, target, [0]*len(candidates))
        return self.ret
    
    def dfs(self, can, temp, idx, tar, used):
        if tar == 0:
            self.ret.append([x for x in temp])
            return
        elif tar < 0: # save time
            return
        
        for i in range(idx, len(can)):
            if i == 0 or can[i] != can[i-1] or used[i-1] == 1:
                temp.append(can[i])
                used[i] = 1
                self.dfs(can, temp, i+1, tar - can[i], used)
                temp.pop()
                used[i] = 0