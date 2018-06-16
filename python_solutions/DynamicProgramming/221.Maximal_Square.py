# 1. P[0][j] = matrix[0][j] (topmost row);
# 2. P[i][0] = matrix[i][0] (leftmost column);
# 3. For i > 0 and j > 0: if matrix[i][j] = 0, P[i][j] = 0; if matrix[i][j] = 1, P[i][j] = min(P[i - 1][j], P[i][j - 1], P[i - 1][j - 1]) + 1.

class Solution:
    def maximalSquare(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        if not matrix or len(matrix) == 0 or len(matrix[0]) == 0:
            return 0
        
        m, n = len(matrix), len(matrix[0])
        # initial state
        count = [[0]*n for _ in range(m)]
        maxsize = 0
        
        # topmost row
        for j in range(n):
            count[0][j] = ord(matrix[0][j]) - ord('0')
            maxsize = max(maxsize, count[0][j])
        # leftmost coloumn
        for i in range(m):
            count[i][0] = ord(matrix[i][0]) - ord('0')
            maxsize = max(maxsize, count[i][0])
        
        for i in range(1, m):
            for j in range(1, n):
                if matrix[i][j] == '1':
                    count[i][j] = min(count[i-1][j-1], count[i-1][j], count[i][j-1]) + 1
                    maxsize = max(maxsize, count[i][j])
        
        return maxsize * maxsize
        
        
        