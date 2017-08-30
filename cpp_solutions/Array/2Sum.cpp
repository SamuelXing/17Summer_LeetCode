/*
 *Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 *
 * */

// Note: Using hash map, the time complexity will be O(N)

#include<vector>
#include<unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target){
		vector<int> rst;
		unordered_map<int, int> hash;

		for(int i=0; i < nums.size(); i++)
		{
			if(hash.find(target - nums[i]) != hash.end())
			{
				rst.push_back(hash[target-nums[i]]);
				rst.push_back(i);
			}
			hash[nums[i]] = i;
		}

		return rst;
}
