class MyCalendarTwo:

    def __init__(self):
        self.overlaps = []
        self.cals = []

    def book(self, start, end):
        """
        :type start: int
        :type end: int
        :rtype: bool
        """
        for i, j in self.overlaps:
            if start < j and end > i:
                return False
        
        for i, j in self.cals:
            if start < j and end > i:
                self.overlaps.append((max(start, i), min(end, j)))
        
        self.cals.append((start, end))
        return True

# Your MyCalendarTwo object will be instantiated and called as such:
# obj = MyCalendarTwo()
# param_1 = obj.book(start,end)