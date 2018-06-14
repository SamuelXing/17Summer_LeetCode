class Solution(object):
    def isOneEditDistance(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if s == t:
            return False
        
        m, n = len(s), len(t)
        if abs(m-n) > 1:
            return False
        
        # has to ensure s is the longer one
        if m < n:
            m, n = n, m
            t, s = s, t
        
        i = 0 
        while i < n:
            if s[i] == t[i]:
                i += 1
            else:
                if s[i+1:] == t[i:]:
                    return True
                if s[i+1:] == t[i+1:]:
                    return True
                
                return False
        
        return False
        