class Solution:
    def multiply(self, A, B):
        """
        :type A: List[List[int]]
        :type B: List[List[int]]
        :rtype: List[List[int]]
        """
        m, n, k  = len(A), len(A[0]), len(B[0])
        res = [[0 for j in range(k)] for i in range(m)]
        
        for x in range(m):
            for y in range(n):
                if A[x][y] != 0:
                    for z in range(k):
                        if B[y][z] != 0: res[x][z] += A[x][y]*B[y][z]
        
        return res
        