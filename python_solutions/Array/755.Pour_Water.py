class Solution:
    def pourWater(self, heights, V, K):
        """
        :type heights: List[int]
        :type V: int
        :type K: int
        :rtype: List[int]
        """
        while V > 0:
            self.pouring(heights, K, heights[K] + 1, True, True)
            V -= 1
        return heights
        
    def pouring(self, h, idx, bound, goLeft, goRight):
        if goLeft and idx > 0 and h[idx-1] <= h[idx] and self.pouring(h, idx-1, h[idx], True, False):
            return True
        if goRight and idx < len(h)-1 and h[idx+1] <= h[idx] and self.pouring(h, idx+1, h[idx], False, True):
            return True
        
        if h[idx] == bound: return False
        h[idx]+=1
        return True
                