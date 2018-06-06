class Solution:
    def combinationSum3(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: List[List[int]]
        """
        self.ret = []
        self.dfs(n, k, 1, [])
        return self.ret
    
    def dfs(self, n, k, start, temp):
        if n == 0 and len(temp) == k:
            rt = [x for x in temp]
            self.ret.append(rt)
            return
            
        for i in range(start, 10):
            temp.append(i)
            self.dfs(n-i, k, i+1, temp)
            temp.pop()