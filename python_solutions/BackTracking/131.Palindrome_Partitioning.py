# DFS version
class Solution:
    def partition(self, s):
        self.res = []
        self.dfs(s, [])
        return self.res
    
    def dfs(self, s, path):
        if not s:
            self.res.append(path)
            return
        
        for i in range(1, len(s)+1):
            if s[:i] == s[i-1::-1]:
                self.dfs(s[i:], path+[s[:i]])