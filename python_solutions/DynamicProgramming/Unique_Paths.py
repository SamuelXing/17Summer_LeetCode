class Solution:
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        
        # init list
        mp = []
        for i in range(m):
            mp.append([0]*n)
        
        for i in range(m):
            for j in range(n):
                if i==0 or j==0:
                    mp[i][j] = 1
                else:
                    mp[i][j] = mp[i-1][j] + mp[i][j-1]
        return mp[m-1][n-1]
    
