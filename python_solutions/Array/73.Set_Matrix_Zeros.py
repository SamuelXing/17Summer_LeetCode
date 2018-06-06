class Solution:
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """

        # space O(m+n)
        if len(matrix) == 0:
            return
        m, n = len(matrix), len(matrix[0])
        rowFlags = [False]*m
        colFlags = [False]*n
        for r in range(m):
            for c in range(n):
                if matrix[r][c] == 0:
                    rowFlags[r] = True
                    colFlags[c] = True
        
        for r in range(m):
            for c in range(n):
                if rowFlags[r] or colFlags[c]:
                    matrix[r][c] = 0
        
        return

# in-place solution
class Solution:
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        # in-Place solution
        
        row0hasZero, col0hasZero = False, False
        
        m = len(matrix)
        n = len(matrix[0])
        
        for r in range(m):
            for c in range(n):
                if matrix[r][0] == 0:
                    col0hasZero = True
                if matrix[0][c] == 0:
                    row0hasZero = True
        
        for r in range(1, m):
            for c in range(1, n):
                if matrix[r][c] == 0:
                    matrix[r][0] = 0
                    matrix[0][c] = 0
        
        # zero up
        for r in range(1, m):
            for c in range(1, n):
                if matrix[r][0] == 0 or matrix[0][c] == 0:
                    matrix[r][c] = 0
        
        if row0hasZero:
            for c in range(n):
                matrix[0][c] = 0
        
        if col0hasZero:
            for r in range(m):
                matrix[r][0] = 0