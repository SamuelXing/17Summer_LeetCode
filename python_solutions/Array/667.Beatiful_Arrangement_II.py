class Solution:
    def constructArray(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[int]
        """
        ret = []
        i, j = 1, n
        while i<=j:
            if k > 1: 
                if k & 1:
                    ret.append(i)
                    i = i+1
                else:
                    ret.append(j)
                    j = j -1
                k -= 1
            else:
                ret.append(i)
                i+=1
            
        return ret