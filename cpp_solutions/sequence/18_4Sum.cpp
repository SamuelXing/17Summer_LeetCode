/*

Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]

*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() < 4) return {};
        // sort
        sort(nums.begin(), nums.end());
        
        int length = nums.size();
        vector<int> temp;
        vector<vector<int>> rst;
        for(int i=0; i< length -3; i++)
        {
            if (i && nums[i] == nums[i - 1]) continue;
            for(int j=i+1; j< length-2; j++)
            {
                if(j != i+1 && nums[j] == nums[j-1]) continue;
                int start = j+1, end = length-1;
                int currTarget = target - nums[i] - nums[j];
                while(start < end)
                {
                    if(nums[start] + nums[end] == currTarget)
                    {
                        temp.clear();
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[start]);
                        temp.push_back(nums[end]);
                        rst.push_back(temp);
                        while(start < end && nums[start] == nums[start+1]) start++;
                        while(start < end && nums[end] == nums[end - 1]) end --;
                        start ++;
                        end --;
                    }
                    else if(nums[start] + nums[end] < currTarget)
                    {
                        start ++;
                    }
                    else
                    {
                        end --;
                    }
                }
            }
        }
        return rst;
    }
};