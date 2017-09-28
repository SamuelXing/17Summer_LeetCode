/*
	A non-negative numbers can be regarded as product of its factors.
	Write a function that takes an integer n and return all possible combinations of its factors.

Example
Given n = 8
return [[2,2,2],[2,4]]
// 8 = 2 x 2 x 2 = 2 x 4.

Given n = 1
return []

Given n = 12
return [[2,6],[2,2,3],[3,4]]

*/

class Solution {
public:
	void dfs(int start, int remain){
		if(!path.empty()){
			path.push_back(remain);
			ans.push_back(path);
			path.pop_back();
		}

		for(int i=start; i<remain; i++){
			if(remain/i < i){
				break;
			}

			if(remain%i == 0){
				path.push_back(i);
				dfs(i, remain/i);
				path.pop_back();
			}
		}
	}
    /*
     * @param n: An integer
     * @return: a list of combination
     */
    vector<vector<int>> getFactors(int n) {
        // write your code here
    	dfs(2, n);
    	return ans;
    }

private:
	vector<vector<int>> ans;
	vector<int> path;
};

