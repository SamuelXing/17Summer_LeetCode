class Solution:
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        ret = []
        for i in range(rowIndex+1):
            ret.append(1);
            
        for i in range(0, rowIndex+1, 1):
            for j in range(i-1, 0, -1):
                ret[j] = ret[j-1]+ret[j]
        return ret
        