'''

First time number appear -> save it in "ones"

Second time -> clear "ones" but save it in "twos" for later check

Third time -> try to save in "ones" but value saved in "twos" clear it.
-----------------------------------------------------------------------

VAR ^ 4,
if there is no 4 in VAR, means SAVE 4 into VAR.
if there is 4 in VAR, means CLEAR 4 from VAR.

7 & (~4) = 3, means CLEAR 4 from 7.

VAR & (-4), means CLEAR 4 form VAR.

For example, an array {1, 2, 2, 1, 1, 7, 2 }

        1        2       2       1         1       7     2
  one  [1]     [1,2]    [1]    [null]    [null]   [7]   [7] (<=Answer)
  two  [null]  [null]   [2]    [1,2]     [2]      [2]   [0]
  
  Index form 0 to 6.....====>>>>>>
※ which [N] means the info in variables.

'''

class Solution:
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ones, twos = 0, 0
        for x in nums:
            ones = (ones ^ x) & ~twos
            twos = (twos ^ x) & ~ones
        
        return ones
        