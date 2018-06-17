# brute-force
class Solution:
    def countArrangement(self, N):
        """
        :type N: int
        :rtype: int
        """
        self.count = 0
        nums = [i for i in range(1, N+1)]
        self.permutation(nums, 0)
        return self.count
    
    def permutation(self, nums, l):
        if l == len(nums):
            self.count += 1
            return 
        
        for i in range(l, len(nums)):
            nums[i], nums[l] = nums[l], nums[i]
            if nums[l] % (l+1) == 0 or (l+1) % nums[l] == 0:
                self.permutation(nums, l+1)
            nums[i], nums[l] = nums[l], nums[i]

# DFS + backtracking
class Solution:
    def countArrangement(self, N):
        """
        :type N: int
        :rtype: int
        """
        self.count = 0
        self.helper(N, 1, [False]*(N+1))
        return self.count
    
    def helper(self, N, pos, used):
        if pos > N:
            self.count += 1
            return
        
        for i in range(1, N+1):
            if used[i] == False and ( i % pos == 0 or pos % i == 0):
                used[i] = True
                self.helper(N, pos+1, used)
                used[i] = False

# DFS + cache
cache = {}
class Solution(object):
    def countArrangement(self, N):
        def helper(i, X):
            if i == 1:
                return 1
            key = i, X
            if key in cache:
                return cache[key]
            total = sum(helper(i - 1, X[:j] + X[j + 1:])
                        for j, x in enumerate(X)
                        if x % i == 0 or i % x == 0)
            cache[key] = total
            return total
        return helper(N, tuple(range(1, N + 1)))