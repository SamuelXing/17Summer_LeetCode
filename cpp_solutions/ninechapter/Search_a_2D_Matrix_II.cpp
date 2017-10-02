/*
Write an efficient algorithm that searches for a value in an m x n matrix, return the occurrence of it.

This matrix has the following properties:

Integers in each row are sorted from left to right.
Integers in each column are sorted from up to bottom.
No duplicate integers in each row or column.

Example
Consider the following matrix:

[
  [1, 3, 5, 7],
  [2, 4, 7, 8],
  [3, 5, 9, 10]
]
Given target = 3, return 2.

*/

class Solution {
public:
    /*
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int>> &matrix, int target) {
        // write your code here
        int ans = 0;
        for(int i=matrix.size()-1, j=0; i>=0 && j< matrix.size() ;){
        	if(matrix[i][j] == target){
        		ans++;
        		i--;
        		j++;
        	}	
        	else if(matrix[i][j] > target)
        		i--;
        	else if(matrix[i][j] < target)
        		j++;
        }
        return ans;
    }
};