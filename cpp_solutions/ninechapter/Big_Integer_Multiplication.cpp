/*
Given two non-negative integers num1 and num2 represented as strings,
return the product of num1 and num2

Example
The length of both num1 and num2 is < 110.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.

*/

class Solution {
public:
    /*
     * @param num1: a non-negative integers
     * @param num2: a non-negative integers
     * @return: return product of num1 and num2
     */
    string multiply(string &num1, string &num2) {
        // write your code here
        int len1 = num1.size(), len2 = num2.size();
        int len3 = len1 + len2;
        int i, j, carry, product;

        string rst = "";
        vector<int> rst_vec(len3, 0);

        for(i = len1-1; i>=0; i--){
        	carry = 0;
        	for(j= len2-1; j>=0; j--){
        		product = carry + rst_vec[i+j+1] + (num1[i] - '0')*(num2[j] - '0');
        		rst_vec[i+j+1] = product % 10;
        		carry = product/10;
        	}
        	rst_vec[i+j+1] = carry;
        }

        // get the first element not equal to 0
        int k;
        for(k=0; k<len3-1 && rst_vec[k] == 0; k++){}

        for(;k<len3;k++){
        	rst+=to_string(rst_vec[k]);
        }
        return rst;
    }
};