class Comparable:
    def __init__(self, n):
        self.val = str(n)
    
    def __lt__(self, other):
        return self.val + other.val > other.val + self.val
    
    def __gt__(self, other):
        return self.val + other.val < other.val + self.val
    
    def __eq__(self, other):
        return self.val + other.val == other.val + self.val
    
class Solution:
    def largestNumber(self, num):
        num = [Comparable(x) for x in num]
        num.sort()
        return ''.join(n.val for n in num).lstrip('0') or '0'