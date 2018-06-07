class Solution:
    # @param {integer[]} nums
    # @return {integer[]}
    def majorityElement(self, nums):
        count1, count2, candidates1, candidates2 = 0, 0, 0, 1
        for x in nums:
            if x == candidates1:
                count1 += 1
            elif x == candidates2:
                count2 += 1
            elif count1 == 0:
                candidates1, count1 = x, 1
            elif count2 == 0:
                candidates2, count2 = x, 1
            else:
                count1, count2 = count1 - 1, count2 - 1
        
        return [n for n in (candidates1, candidates2) if nums.count(n) > len(nums)//3]


# Majority Voting Algorithm, parallel impleemntation
# https://gregable.com/2013/10/majority-vote-algorithm-find-majority.html
# candidate = 0
# count = 0
# for candidate_i, count_i in parallel_output:
#   if candidate_i = candidate:
#     count += count_i
#   else if count_i > count:
#     count = count_i - count
#     candidate = candidate_i
#   else:
#     count = count - count_i