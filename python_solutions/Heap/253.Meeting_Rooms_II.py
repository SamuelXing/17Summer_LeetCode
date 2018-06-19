# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    def minMeetingRooms(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: int
        """
        starts = sorted(i.start for i in intervals)
        ends = sorted(i.end for i in intervals)
        
        e, numRooms, available = 0, 0, 0
        for start in starts:
            while ends[e] <= start:
                e += 1
                available += 1
            if available:
                available -= 1
            else:
                numRooms += 1
        
        return numRooms

class Solution:
    def minMeetingRooms(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: int
        """
        intervals.sort(key = lambda x: x.start)
        heap = []
        for i in intervals:
            if heap and i.start >= heap[0]:
                heapq.heapreplace(heap, i.end)
            else:
                heapq.heappush(heap, i.end)
        return len(heap)
        