/*

Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.

*/

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp{0};
        dp.resize(n+1, INT_MAX);
        for(int i=1, k; (k=i*i)<=n; i++){
        	for(int j=k; j<=n; j++){
        		if(dp[j]>dp[j-k]+1)
        			dp[j] = dp[j-k] + 1;
        	}
        }
        return dp[n];
    }
};