/*
* 
* Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
* 
* Notes: translating this problem to largest_rectangle_area
*
**/

#include <vector>
#include <stack>

int maximalRectangle(vector<vector<char>>& matrix){
	// rule out empty cases
	if(matrix.empty() || matrix[0].empty()){
		return 0;
	}

	// counting the dimensions of the matrix
	int m = matrix.size();
	int n = matrix[0].size();

	// initialing a new matrix, to record the translated results
	vector<vector<int>> heights(m, vector<int>(n,0));

	// translating
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(matrix[i][j] == '0'){
				heights[i][j] = 0;
			}else{
				heights[i][j] = (i == 0) ? 1: heights[i-1][j] + 1;
			}
		}
	}

	// find the maximum area for each row
	int rst = 0;
	for(int i = 0; i < m; i++){
		rst = max(rst, largestRectangleArea(heights[i]));
	}

	return rst;
}

int largestRectangleArea(vector<int>& height)
{
	if(height.size() == 0) return 0;
	// result
	int rst = 0;
	// counter
	int i = 0;
	stack<int> s;
	// push 0 back to the height array, in order to continue the counting until the end last element
	height.push_back(0);
	

	while(i < height.size())
	{
		if(s.empty() || !s.empty() && height[i] > height[s.top()]){
			s.push(i);
			i++;
		}
		else{
			int tmp = s.top();
			s.pop();
			rst = max(rst, height[tmp] * (s.empty()?i:i-s.top()-1));
		}
	}
	return rst;
}