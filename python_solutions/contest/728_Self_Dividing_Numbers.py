class Solution:
    def selfDividingNumbers(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: List[int]
        """
        ret = []
        for i in range(left, right+1, 1):
            if self.isSelfDividingNumber(i):
                ret.append(i)
        return ret
    
    def isSelfDividingNumber(self, i):
        tmp = i
        while tmp:
            digit = tmp%10
            tmp = int(tmp/10)
            if digit == 0:
                return False
            if i%digit != 0:
                return False
        return True
                
    