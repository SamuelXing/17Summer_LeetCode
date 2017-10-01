/*

Given two Sparse Matrix A and B, return the result of AB.

You may assume that A's column number is equal to B's row number.

Example
A = [
  [ 1, 0, 0],
  [-1, 0, 3]
]

B = [
  [ 7, 0, 0 ],
  [ 0, 0, 0 ],
  [ 0, 0, 1 ]
]


     |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
                  | 0 0 1 |

*/

// Solution 1: Regular multiplication + rule out;
class Solution {
public:
    /*
     * @param A: a sparse matrix
     * @param B: a sparse matrix
     * @return: the result of A * B
     */
    vector<vector<int>> multiply(vector<vector<int>> &A, vector<vector<int>> &B)
    {
        // write your code here
        int ma = A.size();
        int na = A[0].size();
        int nb = B[0].size();

        vector<vector<int>> rst(ma, vector<int>(nb, 0));
        for(int i = 0; i<= ma-1; i++){
        	for(int k=0; k<= na -1; k++){
        		if(A[i][k]!=0){
        			for(int j=0; j<= nb-1; j++){
        				rst[i][j] += A[i][k]*B[k][j];
        			}
        		}
        	}
        }

        return rst;
    }
};

// Solution 2
// aims to implement A[i][k]*B[k][j], and A[i][k]!=0 && B[k][j] !=0
class Solution {
public:
    /*
     * @param A: a sparse matrix
     * @param B: a sparse matrix
     * @return: the result of A * B
     */
    vector<vector<int>> multiply(vector<vector<int>> &A, vector<vector<int>> &B) {
        // write your code here
        vector<vector<int>> ans(A.size(), vector<int>(B[0].size(), 0));
        vector<vector<pair<int, int>>> v(B.size());

        // manipulate B
        for(int i=0; i<B.size(); i++){
        	for(int j=0; j<B[0].size(); j++){
        		if(B[i][j] != 0)
        			v[i].push_back({j,B[i][j]});
        	}
        }

        // multiply A, B
        for(int i=0; i< A.size(); i++){
        	for(int k=0; k< A[0].size(); k++){
        		if(A[i][k] != 0){
        			for(int p=0; p< v[k].size(); p++){
        				int j=v[k][p].first;
        				int val = v[k][p].second;
        				ans[i][j] += A[i][k]*val;
        			}
        		}
        	}
        }
        return ans;
    }
};





