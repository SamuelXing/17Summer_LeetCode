/*

Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

*/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
    	vector<vector<int>> rst;
    	vector<int> permutation;
    	bool used[nums.size()];

    	for(int i=0; i<nums.size(); i++){
    		used[i] = false;
    	}

    	sort(nums.begin(), nums.end());

    	dfs(rst, permutation, nums, used);
    	return rst;
    }
private:
	void dfs(vector<vector<int>>& rst, vector<int>& permutation, vector<int>& nums, bool used[]){
		if(nums.size() == permutation.size()){
			rst.push_back(permutation);	
			return;
		}

		for(int i=0; i< nums.size(); i++){
			if(used[i])
				continue;
			if(i>0 && used[i-1] == false && nums[i]==nums[i-1])
				continue;

			used[i] = true;
			permutation.push_back(nums[i]);
      dfs(rst, permutation, nums, used);
      permutation.pop_back();
      used[i] = false;
		}

	}
};

