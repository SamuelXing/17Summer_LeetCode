/*

Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

*/

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
      vector<vector<int>> ans; vector<int> stack;
      for(int i=1; i<=k; ++i) stack.push_back(i);
      ans.push_back(stack);
      while(1){
      	while(stack.size()>0 && stack.back() == n+stack.size()-k) stack.pop_back();
      	if(stack.size() == 0) break;
      	++stack[stack.size()-1];
      	while(stack.size() < k) stack.push_back(stack[stack.size()-1]+1);
      	ans.push_back(stack);
      }
      return ans;  
    }
};


