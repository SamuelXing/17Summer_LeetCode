/*
	Given two non-negative integers num1 and num2 represented as string, 
	return the sum of num1 and num2.

Example
Given num1 = "123", num2 = "45"
return "168"

*/

class Solution {
public:
    /*
     * @param num1: a non-negative integers
     * @param num2: a non-negative integers
     * @return: return sum of num1 and num2
     */
    string addStrings(string &num1, string &num2) {
        // write your code here
        int i=num1.length()-1;
        int j=num2.length()-1;
        int carry = 0;
  		string ans = "";

  		while(i>=0 || j>=0){
  			if(i>=0){
  				carry += num1[i] -'0';
  				i--;
  			}
  			if(j>=0){
  				carry += num2[j] - '0';
  				j--;
  			}
  			ans = to_string(carry%10)+ans;
  			carry=carry / 10;
  		}

  		if(carry){
  			ans = to_string(carry)+ans;
  		}	

  		return ans;	       
    }
};