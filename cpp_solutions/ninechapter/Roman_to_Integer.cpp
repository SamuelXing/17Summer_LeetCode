/*
* Given a roman numeral, convert it to an integer.

* The answer is guaranteed to be within the range from 1 to 3999.
*
*/

class Solution {
public:
    /*
     * @param s: Roman representation
     * @return: an integer
     */
    int romanToInt(string &s) {
        // write your code here
        int ans = 0;
        ans = toInt(s[0]);
        for(int i=1; i<s.length(); i++){
        	ans += toInt(s[i]);
        	if(toInt(s[i-1])<toInt(s[i]))
        		ans -= toInt(s[i-1])*2;
        }
        return ans;
    }

    int toInt(char s){
    	switch(s){
    		case 'I': return 1;
    		case 'V': return 5;
    		case 'X': return 10;
    		case 'L': return 50;
    		case 'C': return 100;
    		case 'D': return 500;
    		case 'M': return 1000;
    	}
    	return 0;
    }
};