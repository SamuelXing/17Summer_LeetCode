# find if there is a triple
# idea 1, if there is not a triple, when in which case, the conclusion will fail
# idea 2, if ther is already exists a triple, what properties must be satisfied

class Solution:
    def splitArray(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        N = len(nums)
        if N < 7:
            return False
        
        prefixSum = [0]*N
        prefixSum[0] = nums[0]
        for i in range(1, N):
            prefixSum[i] = prefixSum[i-1] + nums[i]

        for j in range(3, N-3):
            ss = set([])
            for i in range(1, j-1):
                if prefixSum[i-1] == prefixSum[j-1] - prefixSum[i]:    
                    ss.add(prefixSum[i-1])
            
            for k in range(j+2, N-1):
                if prefixSum[N-1] - prefixSum[k] == prefixSum[k-1] - prefixSum[j] and (prefixSum[k-1] - prefixSum[j]) in ss:
                    return True
        
        return False