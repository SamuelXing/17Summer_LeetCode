class Solution(object):
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        if s is None or len(s) == 0:
            return 0
        
        self.count = 0
        for i in range(len(s)):
            self.check(s, i, i) # check Odd
            self.check(s, i, i+1) # check Even
        
        return self.count
    
    def check(self, s, l, r):
        while l >= 0 and r < len(s) and s[l] == s[r]:
            self.count += 1
            l -= 1
            r += 1