class Solution:
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        ret = []
        if numRows == 0:
            return ret     
        ret.append([1])
        if numRows == 1:
        	return ret
        ret.append([1,1])
        if numRows == 2:
        	return ret
        for i in range(2, numRows):
            temp = [1,1]
            for j in range(i, 1, -1):
                temp.insert(1, ret[i-1][j-1]+ret[i-1][j-2])
            ret.append(temp)
        return ret 
