# how to multiply
# rule out leading zeros
# has to go through left to right, ----->>
class Solution(object):
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        m, n = len(num1), len(num2)
        res = [0]*(m+n)
        
        for i in range(m-1, -1, -1):
            for j in range(n-1, -1, -1):
                product = (ord(num1[i])-ord('0'))*(ord(num2[j])-ord('0'))
                p1, p2 = i+j, i+j+1
                
                curSum = product + res[p2]
                res[p1] += curSum//10
                res[p2] = curSum % 10
        
        
        res = ''.join(list(map(str, res))).lstrip('0')
        return res if res else '0'

s = Solution()
s.multiply("123", "456")
    