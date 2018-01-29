class Solution:
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        ret = 0
        temp = x
        while x:
            ret = ret*10 + x%10
            x = int(x/10)
        return temp == ret
        