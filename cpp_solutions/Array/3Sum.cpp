/*
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
 * Find all unique triplets in the array which gives the sum of zero.
 *
 * */

// Notes: two pointers

#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums)
{
	vector<vector<int>> rst;

	// sort the array
	sort(nums.begin(), nums.end());

	for(int i=0; i < nums.size(); i++){
		if(i > 0 && nums[i] == nums[i-1])
		{
			continue;
		}

		// convert this problem to 2Sum
		int start = i+1, end = nums.size() - 1;
		int target = -nums[i];

		while(start < end){
			if(start > i+1 && nums[start] == nums[start-1]){
				start++;
				continue;
			}

			if(nums[start] + nums[end] < target)
			{
				start++ ;
			}
			else if(nums[start] + nums[end] > target)
			{
				end--;
			}
			else
			{
				vector<int> temp;
				temp.push_back(nums[i]);
				temp.push_back(nums[start]);
				temp.push_back(nums[end]);
				rst.push_back(temp);
				start++;
			}
		}
	}	
	return rst;
}
