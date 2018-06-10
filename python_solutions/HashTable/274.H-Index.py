class Solution:
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        N = len(citations)
        # each i i in range(N+1) represent the number of hIdx(key)
        hIdx = [0] * (N+1)
        
        for c in citations:
            if c >= N:
                hIdx[N] += 1
            else:
                hIdx[c] += 1
        
        sumIdx = 0
        for idx in range(N, -1, -1):
            sumIdx += hIdx[idx]
            if sumIdx >= idx:
                return idx
        return 0