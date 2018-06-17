class Solution:
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        nums = [i for i in range(1, n+1)]
        ret = ""
        fact = [1]
        for i in range(1, n):
            fact.append(fact[-1] * i)
            
        for i in range(n):
            index = (k-1)//fact[n-i-1]
            ret += str(nums[index])
            nums.remove(nums[index])
            k -= index*fact[n-i-1]
            
        return ret
            