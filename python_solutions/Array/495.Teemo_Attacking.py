class Solution:
    def findPoisonedDuration(self, timeSeries, duration):
        """
        :type timeSeries: List[int]
        :type duration: int
        :rtype: int
        """
        ret = len(timeSeries)*duration
        for i in range(1, len(timeSeries)):
            ret -= max(0, duration - (timeSeries[i] - timeSeries[i-1]))
        return ret