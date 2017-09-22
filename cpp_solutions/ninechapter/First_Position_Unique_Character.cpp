/*

Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Example
Given s = "lintcode", return 0.

Given s = "lovelintcode", return 2.

*/

class Solution {
public:
    /*
     * @param s: a string
     * @return: it's index
     */
    int firstUniqChar(string &s) {
        // write your code here
    	 vector<int> hash(256, 0);
    	for(int i=0; i< s.size(); i++){
    		hash[s[i]]++;
    	}

    	for(int i=0; i<s.size();i++){
    		if(hash[s[i]] == 1)
    			return i;
    	}
        return -1;
    }
};

