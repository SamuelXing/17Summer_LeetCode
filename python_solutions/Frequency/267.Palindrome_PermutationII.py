class Solution:
    def generatePalindromes(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        # counte the frequency of each character
        d = collections.Counter(s)
        
        # rule out "ab"
        flag, alist = [], ''
        for k, v in d.items():
            if v % 2 != 0:
                flag += [k]
            alist += k*(v//2)
                
        if len(flag) > 1:
            return []
        mid = flag[0] if flag else ''
        
        # prepare dfs + backtracking
        visited, self.res = [False]*len(alist), []
        self.dfs(alist, visited, "", mid)
        return self.res
    
    def dfs(self, alist, visited, tmp, mid):
        if len(tmp) == len(alist):
            self.res.append(tmp+mid+tmp[::-1])
            return
        for i in range(len(alist)):
            if i and alist[i] == alist[i-1] and not visited[i-1]: continue
            if not visited[i]:
                visited[i] = True
                self.dfs(alist, visited, tmp+alist[i], mid)
                visited[i] = False