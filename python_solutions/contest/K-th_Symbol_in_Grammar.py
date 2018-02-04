class Solution:
    def kthGrammar(self, N, K):
        """
        :type N: int
        :type K: int
        :rtype: int
        """
        if N == 1:
            return 0
        if K%2 == 1:
            if self.kthGrammar(N-1, int(K/2)+1) == 0:
                return 0
            else:
                return 1
        else:
            if self.kthGrammar(N-1, int(K/2)) == 0:
                return 1
            else:
                return 0