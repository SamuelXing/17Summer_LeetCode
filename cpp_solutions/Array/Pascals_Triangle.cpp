/*
 * Given numRows, generate the first numRows of Pascal's triangle.
 * */

#include<vector>

using namespace std;

vector<vector<int>> generate(int numRows){
	vector<vector<int>> vec;
	vec.resize(numRows);

	for(int i=0; i < numRows; i++){
		vec[i].resize(i+1);	
	 	for(int j=0; j <= i; j++) {
			if(j==0) {
				vec[i][1] = 1;
			}
			else if(j==i) {
				vec[i][i] = 1;
			}
			else{
        vec[i][j]= vec[i-1][j-1]+vec[i-1][j];
			}
		}
	}
	return vec;
}

