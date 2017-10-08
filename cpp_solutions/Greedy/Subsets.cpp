/*

Given a set of distinct integers, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> rst;
		vector<int> subset;

		sort(nums.begin(), nums.end());
		dfs(rst, subset, nums, 0);   
		return rst;     
    }
private:
	void dfs(vector<vector<int>>& rst, vector<int>& subset, vector<int>& nums, int start){
		rst.push_back(subset);
		for(int i= start; i< nums.size(); i++){
			subset.push_back(nums[i]);
			dfs(rst, subset, nums, i+1);
			subset.pop_back();
		}
	}
};




