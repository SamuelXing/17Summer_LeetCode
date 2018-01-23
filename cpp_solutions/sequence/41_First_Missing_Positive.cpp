/*

Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.

*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
  		for(int i=0; i<n; i++)
  		{
  			while(nums[i]!=i+1 && nums[i] >= 1 && nums[i] <= n)
  			{
  				if(nums[nums[i]-1] == nums[i]) 
  				{
  					break;
  				}
  				int temp = nums[i];
  				nums[i] = nums[temp-1];
  				nums[temp-1] = temp;
  			}
  		}    

  		for(int i=0; i<n; i++)
  		{
  			if(nums[i] != i+1)
  			{
  				return i+1;
  			}
  		}  
  		return n + 1;
    }
};