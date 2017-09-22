/*
Given an integer, convert it to a roman numeral.

The number is guaranteed to be within the range from 1 to 3999.
*/

// Solution 1
class Solution {
public:
    /*
     * @param n: The integer
     * @return: Roman representation
     */
    string intToRoman(int n) {
        // write your code here
    	string ans;
    	string Roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    	int value[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    	for(int i=0; i<13; i++){
    		while(n >= value[i]){
    			n -= value[i];
    			ans += Roman[i];
    		}
    	}
    	return ans;
    }
};

// Solution 2
class Solution {
public:
    /*
     * @param n: The integer
     * @return: Roman representation
     */
    string intToRoman(int n) {
        // write your code here
    	vector<string> M = {"", "M", "MM", "MMM"};
        vector<string> C = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        vector<string> X = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string> I = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    	return M[n/1000] + C[(n/100)%10] + X[(n/10)%10] + I[n%10];
    }
};





