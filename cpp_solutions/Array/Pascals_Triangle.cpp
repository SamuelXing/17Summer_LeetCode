/*
 * Given numRows, generate the first numRows of Pascal's triangle.
 * */

#include<vector>

using namespace std;

vector<vector<int>> generate(int numRows){
	for(int i=1; i <= numRows; i++){
		for(int j=1; j <= i; j++) {
			if(j==1) {
				// vec[i][1] = 1
			}
			if(j==i) {
				// vec[i][i] = 1
			}

		}
	}

}

