/*

Given two binary strings, return their sum (also a binary string).

Example:
a = 11

b = 1

Return 100
*/

class Solution {
public:
    /*
     * @param a: a number
     * @param b: a number
     * @return: the result
     */
    string addBinary(string &a, string &b) {
        // write your code here
        int m = a.length()-1;
        int n = b.length()-1;
        int carry = 0;
        string ans = "";
        while(m >=0 || n >=0){
        	if(m >= 0){
        		carry += a[m]-'0';
        		m--;
        	}
        	if(n >= 0){
        		carry += b[n]-'0';
        		n--;
        	}
        	ans = to_string(carry%2) + ans;
        	carry /= 2;
        }

        if(carry){
        	ans = to_string(carry) + ans;
        }
        return ans;
    }
};