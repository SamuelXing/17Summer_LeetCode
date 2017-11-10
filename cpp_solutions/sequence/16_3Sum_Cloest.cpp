/*
	Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {        
        // sort nums   
        sort(nums.begin(), nums.end());
        
        int cloest = nums[0] + nums[1] + nums[2];
        int currTarget;
        for(int i=0; i< nums.size(); i++)
        {
            currTarget = target - nums[i];
            int start = i+1, end = nums.size() - 1;
            while(start < end)
            {
                if(abs(nums[start] + nums[end] - currTarget) < abs(target - cloest))
                {
                    cloest = nums[start] + nums[end] + nums[i];
                }
                if(nums[start]+nums[end] < currTarget)
                {
                   start ++ ; 
                }
                else
                {
                    end --;    
                }
            }
        }
        return cloest;
    }
    
};