/*

Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

*/


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> rst;
        int n = nums.size();
        if(n == 0){
        	rst.push_back(nums);
        	return rst;
        }

        dfs(rst, nums, n-1);

        return rst;
    }

private:
	void dfs(vector<vector<int>>& rst, vector<int> nums, int n){
		if(n == 0)
			rst.push_back(nums);

		for(int i=0; i<=n; i++){
			swap(nums[i], nums[n]);
			dfs(rst, nums, n-1);
			swap(nums[i], nums[n]);
		}
	}
};

