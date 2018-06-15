# Wrose: O(N^2) Average:O(NlogN)
class Solution:
    def findKthLargest(self, nums, k):     
        return sorted(nums)[-k]

# T(n) = T(n/2) + O(n), O(n) is the average time complexity,
# In the worst case, the recursion may become T(n) = T(n - 1) + O(n), the complexity will be O(n^2)
class Solution:
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        l, r = 0, len(nums)-1
        while True:
            pos = self.partition(nums, l, r)
            if pos == k-1:
                return nums[pos]
            elif pos > k-1:
                r = pos - 1
            else:
                l = pos + 1
        
        
    def partition(self, nums, left, right):
        pivot = nums[left]
        l, r = left+1, right
        while l <= r:
            if nums[l] >= pivot:
                l += 1
            elif nums[r] <= pivot:
                r -= 1
            elif nums[l] < pivot and nums[r] > pivot:
                nums[l], nums[r] = nums[r], nums[l]
                l += 1
                r -= 1
        
        nums[left], nums[r] = nums[r], nums[left]
        return r
    
        
        