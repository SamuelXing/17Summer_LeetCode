class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        mp = obstacleGrid
        for i in range(len(mp)):
            for j in range(len(mp[0])):
                if i == 0 and j == 0:
                    mp[i][j] = 1-mp[0][0]
                elif i==0:
                    if mp[i][j] == 1:
                        mp[i][j] = 0
                    else:
                        mp[i][j] = mp[i][j-1]
                elif j==0:
                    if mp[i][j] == 1:
                        mp[i][j] = 0
                    else:
                        mp[i][j] = mp[i-1][j]
                else:
                    if mp[i][j] == 1:
                        mp[i][j] = 0
                    else:
                        mp[i][j] = mp[i][j-1] + mp[i-1][j]
        
        return mp[-1][-1]
                    