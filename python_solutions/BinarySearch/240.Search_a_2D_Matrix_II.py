class Solution:
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        if not matrix or len(matrix) == 0 or len(matrix[0]) == 0:
            return False
        
        m, n = len(matrix), len(matrix[0])
        i, j = len(matrix)-1, 0
        while i>=0 and j < n:
            if target == matrix[i][j]:
                return True
            elif target > matrix[i][j]:
                j += 1
            else:
                i -= 1

        return False
                