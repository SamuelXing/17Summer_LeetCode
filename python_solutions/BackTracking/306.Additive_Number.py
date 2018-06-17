# for all the possibilities of the first two numbers, checking the rest fit
class Solution:
    def isAdditiveNumber(self, num):
        """
        :type num: str
        :rtype: bool
        """
        n = len(num)
        for i, j in itertools.combinations(range(1, n), 2):
            num1, num2 = num[:i], num[i:j]
            if num1 != str(int(num1)) or num2 != str(int(num2)):
                continue
            while j < n:
                num3 = str(int(num1) + int(num2))
                if not num.startswith(num3, j):
                    break
                num1, num2 = num2, int(num3)
                j += len(num3)
            if j == n:
                return True
            
        return False