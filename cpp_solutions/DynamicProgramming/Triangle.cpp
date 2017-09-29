/*

Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]

The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
      if(triangle.size() == 0) return 0;
      vector<int> rst(triangle[triangle.size()-1].size());

      rst[0] = triangle[0][0];
      for(int i=1; i < triangle.size(); i++){
      	for(int j=triangle[i].size()-1; j>=0; j--){
      		if(j == 0){
      			rst[j] = triangle[i][j] + rst[j];
      		}
      		else if(j == triangle[i].size()-1){
      			rst[j] = triangle[i][j] + rst[j-1];
      		}
      		else{
      			rst[j] = min(rst[j-1], rst[j]) + triangle[i][j];
      		}
      	}
      }

      int ret = INT_MAX;
      for (int i = 0; i < rst.size(); ++i)
      {
      	/* code */
      	ret = min(ret, rst[i]);
      }
      return ret;
    }
};