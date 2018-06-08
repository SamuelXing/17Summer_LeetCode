class Solution:
    def maxChunksToSorted(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        n = len(arr)
        
        maxLeft, minRight  = [0]*n, [0]*n
        
        maxLeft[0] = arr[0]
        for i in range(1, n):
            maxLeft[i] = max(maxLeft[i-1], arr[i])
        
        minRight[n-1] = arr[n-1]
        for i in range(n-2, -1, -1):
            minRight[i] = min(minRight[i+1], arr[i])
        
        res = 0
        for i in range(n-1):
            if maxLeft[i] <= minRight[i+1]: res+=1
        
        return res+1