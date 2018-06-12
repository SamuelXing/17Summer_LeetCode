# Has to keep the array sorted!!!!!

# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        intervals = sorted(intervals, key=lambda x: x.start)
        ret = []
        for i in range(len(intervals)):
            if i == 0 or ret[-1].end < intervals[i].start:
                ret.append(intervals[i])
            else:
                ret[-1].end = max(ret[-1].end, intervals[i].end)
        
        return ret
            