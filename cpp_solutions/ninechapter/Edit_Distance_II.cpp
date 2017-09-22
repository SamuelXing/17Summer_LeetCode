/*
 Given two strings S and T,
 determine if they are both one edit distance apart.
*/

// classfied discussion
// substring


class Solution {
public:
    /*
     * @param s: a string
     * @param t: a string
     * @return: true if they are both one edit distance apart or false
     */
    bool isOneEditDistance(string &s, string &t) {
        // write your code here
    	int m = s.size(), n = t.size();

    	// if m-n>1 || n-m >1
    	if(abs(m-n) > 1) return false;
    	if(abs(m-n) = 1){
    		for(int i=0; i < min(m,n); i++){
    			if(s[i]!= t[i]) 
    				return (s.substr(i) == t.substr(i+1)) || (t.substr(i) == s.substr(i+1));
    		}
    	}
    	if(abs(m-n) = 0){
    		int findOne = 0;
    		for(int i=0; i< m; i++){
    			if(s[i]!=t[i]) findOne++;
    		}
    		if(findOne != 1) return false;
    	}

    	return true;
    }

};