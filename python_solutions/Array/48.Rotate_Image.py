class Solution:
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        
        n = len(matrix)
        for j in range(n):
            for i in range(n//2):
                matrix[i][j], matrix[n-i-1][j] = matrix[n-i-1][j], matrix[i][j]
                
        for i in range(n):
            for j in range(i, n):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
        
        