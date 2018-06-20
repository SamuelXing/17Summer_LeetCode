# complexity: O(kLogN)
class Solution:
    def kthSmallest(self, matrix, k):
        m, n = len(matrix), len(matrix[0])
        
        end_row = min(len(matrix), k)
        h = [(matrix[i][0], i, 1) for i in range(end_row)]
        heapq.heapify(h)
        
        for _ in range(k-1):
            elem, i, j = h[0]
            if j < n:
                heapq.heapreplace(h, (matrix[i][j], i, j+1))
            else:
                heapq.heappop(h)
        
        return h[0][0]
                