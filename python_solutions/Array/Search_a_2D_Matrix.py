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
        while start+1 < end:
            mid = start+int((end-start)/2)
            x, y = int(mid/m), int(mid%m)
            if matrix[x][y] == target:
                return True
            elif matrix[x][y] < target:
                start = mid
            else:
                end = mid
                
        x, y = int(start/m), int(start%m)
        if matrix[x][y] == target:
            return True
        x, y = int(end/m), int(end%m)
        if matrix[x][y] == target:
            return True
        
        return False