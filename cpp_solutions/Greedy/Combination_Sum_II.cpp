/*

Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
A solution set is: 
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]

*/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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
        	backTracking(rst,curr,candidates,target,i+1);
        	curr.pop_back();
        	target += candidates[i];
        	while(i<candidates.size()-1 && candidates[i]==candidates[i+1])
        		i++;
        }
    }
};




