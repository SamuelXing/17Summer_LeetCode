class Solution:
    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        ret = [[0 for j in range(n)] for i in range(n)]
        
        up, left = 0, 0
        down, right = n-1, n-1
        direct = 0
        idx = 1
        
        while True:  
            # go right
            if direct == 0:
                for i in range(left, right+1):
                    ret[up][i] = idx
                    idx += 1
                up += 1
            # go down
            if direct == 1:
                for i in range(up, down+1):
                    ret[i][right] = idx
                    idx += 1
                right -= 1
            # go left
            if direct == 2:
                for i in range(right, left-1, -1):
                    ret[down][i] = idx
                    idx += 1
                down -= 1
            # go up
            if direct == 3:
                for i in range(down, up-1, -1):
                    ret[i][left] = idx
                    idx += 1
                left += 1
            if up > down or left > right:
                break
            direct = (direct+1) % 4
        
        return ret
                
                