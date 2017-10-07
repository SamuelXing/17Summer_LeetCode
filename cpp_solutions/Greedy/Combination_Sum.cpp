/*

Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7, 
A solution set is: 
[
  [7],
  [2, 2, 3]
]

*/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> rst;
    	if(candidates.size() == 0 || target < 0)
    		return rst;
    	vector<int> curr;
    	sort(candidates.begin(), candidates.end());
    	backTracking(rst, curr, candidates, target, 0);
    	return rst;
    }

    void backTracking(vector<vector<int>>& rst, vector<int> curr, vector<int> candidates, int target, int level){
    	if(target == 0)
        {
            rst.push_back(curr);
            return;
        }
        else if(target < 0) //save time
            return;
        for( int i = level; i< candidates.size(); ++i){
        	target -= candidates[i];
        	curr.push_back(candidates[i]);
        	backTracking(rst,curr,candidates,target,i);
        	curr.pop_back();
        	target += candidates[i];
        }
    }
};



