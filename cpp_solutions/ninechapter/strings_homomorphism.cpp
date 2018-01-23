/*
* Given two strings s and t, determine if they are isomorphic.

* Two strings are isomorphic if the characters in s can be replaced to get t.

* All occurrences of a character must be replaced with another character while preserving the order of characters. 
* No two characters may map to the same character but a character may map to itself.
*
**/

// Notes: Hash Map, counting appearance of each character at corresponding position.

class Solution {
public:
    /*
     * @param s: a string
     * @param t: a string
     * @return: true if the characters in s can be replaced to get t or false
     */
    bool isIsomorphic(string s, string t) {
    	if(s.size() != t.size()) return false;

        // write your code here
    	unordered_map<char, char> hashmap1;
    	unordered_map<char, char> hashmap2;

    	for(int i=0; i<s.size(); i++){
    		hashmap1[s[i]] = t[i];
    		hashmap2[t[i]] = s[i];
    	}

    	for(int i=0; i<s.size(); i++){
    		if(hashmap1[s[i]] != t[i])
    			return false;
    		if(hashmap2[t[i]] != s[i])
    			return false;
    	}

    	return true;
    }
};



