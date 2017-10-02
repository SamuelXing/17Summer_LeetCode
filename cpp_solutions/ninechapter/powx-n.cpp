/*
Implement pow(x, n).

Example
Pow(2.1, 3) = 9.261
Pow(0, 1) = 0
Pow(1, 0) = 1

*/

class Solution {
public:
    /*
     * @param x: the base number
     * @param n: the power number
     * @return: the result
     */
	// double myPow(double x, int n) will not pass ............... 
    double myPow(double x, long n) {
        // write your code here

        if(n < 0){
        	x = 1 / x;
        	n = -n;
        }
        
        double ans = 1, temp = x;

        while(n != 0){
        	if( n % 2 == 1){
        		ans *= temp;
        	}
        	temp *= temp;
        	n /= 2;
        }
        return ans;
    }
};