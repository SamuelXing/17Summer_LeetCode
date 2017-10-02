/*

You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise).

Example
Given a matrix

[
    [1,2],
    [3,4]
]
rotate it by 90 degrees (clockwise), return

[
    [3,1],
    [4,2]
]

*/

class Solution {
public:
    /*
     * @param matrix: a lists of integers
     * @return: 
     */
    void rotate(vector<vector<int>> &matrix) {
        // write your code here
    	int n = matrix.size();
    	UpDownRotate(matrix, n);
    	DiagnalRotate(matrix, n);
    }
private:
	// up-down reverse
	void UpDownRotate(vector<vector<int>> &matrix, int n){
		for(int i=0; i<n/2; i++){
			for(int j=0; j<n; j++){
				int temp = matrix[i][j];
				matrix[i][j] = matrix[n-i-1][j];
				matrix[n-i-1][j] = temp; 
			}
		}
	}

	//  diagonal reverse
	void DiagnalRotate(vector<vector<int>> &matrix, int n){
		for(int i=0; i<n; i++){
			for(int j=i; j<n; j++){
				int temp = matrix[i][j];
				matrix[i][j] = matrix[j][i];
				matrix[j][i] = temp; 
			}
		}
	}

};