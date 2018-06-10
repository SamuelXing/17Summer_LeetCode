class Solution:
    def fractionToDecimal(self, numerator, denominator):
        """
        :type numerator: int
        :type denominator: int
        :rtype: str
        """
        
        ret, hashMap = [], {}
        
        if numerator == 0:
            return "0"
        
        if (numerator > 0)^(denominator > 0):
            ret.append('-')
        
        # handle integral part
        n, d = abs(numerator), abs(denominator)
        ret.append(str(n//d))
        remain = n % d
        
        if remain != 0:
            ret.append('.')
        else:
            return ''.join(ret)
            
        # handle frational part
        while remain != 0:
            if remain in hashMap:
                idx = hashMap[remain]
                return ''.join(ret[:idx])+'('+''.join(ret[idx:])+')'
            hashMap[remain] = len(ret)
            ret.append(str((remain*10)//d)) #
            remain = (remain*10)%d
        
        return ''.join(ret)
    