/*
* Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

* Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 40,000.

* The order of output does not matter.
*

Given s = "cbaebabacd" p = "abc"

return [0, 6]

*/

class Solution {
public:
    /*
     * @param s: a string
     * @param p: a string
     * @return: a list of index
     */
    vector<int> findAnagrams(string &s, string &p) {
        // write your code here
        vector<int> ans;
        vector<int> window(256, 0), pCnt(256, 0);

        if(s.size() < p.size())
        	return ans;

        for(int i=0; i< p.size(); i++){
        	pCnt[p[i]]++;
        	window[s[i]]++;
        }
        if(equal(pCnt, window))
        	ans.push_back(0);
        for(int i=p.size(); i < s.size(); i++){
        	window[s[i]]++;
        	window[s[i - p.size()]]--;
        	if(equal(window, pCnt))
        		ans.push_back(i - p.size() + 1);
        }
        return ans;
    }
private:
	bool equal(vector<int>& v1, vector<int>& v2){
		for(int i=0; i< v1.size(); i++){
			if(v1[i] != v2[i]) return false;
		}
		return true;
	}
};