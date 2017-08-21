/*
 * Given an index k, return the kth row of the Pascal's triangle.
 *
 * For example, given k = 3,
 * Return [1,3,3,1].
 *
 * */
#include<vector>

using namespace std;

vector<int> getRow(int rowIndex){
	vector<int> vec;
	vec.resize(rowIndex + 1, 1);

	for(int i=0; i< rowIndex+1; i++){
		for(int j=i-1; j >= 1; j--)
		{
			vec[j] = vec[j-1]+vec[j];
		}
	}
	return vec;
}
