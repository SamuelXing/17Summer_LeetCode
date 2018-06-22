class Solution:
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        l, r, length = 0, len(citations)-1, len(citations)
        while l <= r:
            mid = l + (r-l)//2
            if citations[mid] >= (length - mid):
                r = mid - 1
            else:
                l = mid + 1
        return length - l