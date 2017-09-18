/*
* Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

* Note: You can only move either down or right at any point in time.
*
**/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(!m || !n) return 0;
        int sumGrid[m][n];
        sumGrid[0][0] = grid[0][0];

        // initialize
        for(int i=1; i<m; i++){
        	sumGrid[i][0] = sumGrid[i-1][0] + grid[i][0];
        }
		for(int i=1; i<n; i++){
			sumGrid[0][i] = sumGrid[0][i-1] + grid[0][i];
        }

        for(int i=1; i<m; i++){
        	for(int j=1; j<n; j++){
        		sumGrid[i][j] = min(sumGrid[i-1][j] + grid[i][j], sumGrid[i][j-1] + grid[i][j]);
        	}
        }  

        return sumGrid[m-1][n-1];
    }
};