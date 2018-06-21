# how to multiply
# rule out leading zeros
class Solution:
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        m, n = len(num1), len(num2)
        pos = [0]*(m+n)
        
        for i in range(m-1, -1, -1):
            for j in range(n-1, -1, -1):
                mul = (ord(num1[i]) - ord('0')) * (ord(num2[j]) - ord('0'))
                p1, p2 = i+j, i+j+1
                
                sum = mul + pos[p2]
                pos[p1] += sum // 10
                pos[p2] = sum % 10
        
        print(pos)
        res = []
        for i in range(len(pos)):
            if pos[i] == 0 and len(res) == 0:
                continue
            else:
                res.append(str(pos[i]))
        print(res)
        return ''.join(res) if res else '0'

s = Solution()
s.multiply("123", "456")
    