class Solution:
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        ret = [triangle[0]]
        for i in range(1, len(triangle)):
            ret.append([])
            for j in range(len(triangle[i])):
                if j-1>=0 and j < len(triangle[i-1]):
                    ret[i].append(min(ret[i-1][j-1], ret[i-1][j])+triangle[i][j])
                elif j == len(triangle[i-1]):
                    ret[i].append(ret[i-1][j-1]+triangle[i][j])
                else:
                    ret[i].append(ret[i-1][j]+triangle[i][j])
        print(ret) 
        minvalue = min(ret[len(triangle)-1])
        return minvalue