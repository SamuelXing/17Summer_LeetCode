/*
* Search a 2D Matrix
*
* Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
* Integers in each row are sorted from left to right.
* The first integer of each row is greater than the last integer of the previous row.
* 
* Notes: obviously, using binary search, 
*/

#include <vector>
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target){
	// rule out edge cases
	// have to notice the sequence, incase m or n equals 0
	int n = matrix.size();
	if(n == 0){ return false; }
	int m= matrix[0].size();
	if(m == 0) {return false; }

	// initialize
	int start = 0, end = m * n -1;

	// binary search
	while(start + 1 < end){
		int mid = (start + end)/2;

		int row = mid / m;
		int col = mid % m;

		if(matrix[row][col] < target){
			start = mid;
		}
		else {
			end = mid;
		}
	}

	if(matrix[start/m][start%m] == target) {return true;}
	if(matrix[end/m][end%m] == target){return true;}

	return false;
}