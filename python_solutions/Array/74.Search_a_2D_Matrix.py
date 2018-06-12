class Solution:
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return False
        
        n, m = len(matrix), len(matrix[0])
        start, end = 0, n*m-1
        while start <= end:
            mid = start+int((end-start)/2)
            x, y = int(mid/m), int(mid%m)
            if matrix[x][y] == target:
                return True
            elif matrix[x][y] < target:
                start = mid+1
            else:
                end = mid -1
                
        return False