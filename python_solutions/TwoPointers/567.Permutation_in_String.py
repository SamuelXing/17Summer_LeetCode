# Someone else's solution.....
class Solution:
    def checkInclusion(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        A, B = [ord(x) - ord('a') for x in s1], [ord(x) - ord('a') for x in s2]
        
        target = [0]*26
        for x in A:
            target[x] += 1
        
        window = [0]* 26
        for i, c in enumerate(B):
            window[c] += 1
            if i >= len(A):
                window[B[i-len(A)]] -= 1
            if window == target:
                return True
        
        return False
        
class Solution:
    def checkInclusion(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        # rephrase the target
        target = [0]*26
        
        # count word
        for c in s1:
            target[ord(c) - ord('a')] += 1
        
        window = [0]* 26
        for i, c in enumerate(s2):
            window[ord(c) - ord('a')] += 1
            # shrink window when exceed size
            if i >= len(s1):
                window[ord(s2[i-len(s1)]) - ord('a')] -= 1
            if window == target:
                return True
        
        return False  
