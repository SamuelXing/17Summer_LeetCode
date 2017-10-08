/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

TAG:
HashTable, two pointer, string

*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
  		int ans = 0, left = 0, len = s.length();
  		int dict[255];
  		memset(dict, -1, sizeof(dict));

  		for(int i=0; i < len; i++){
  			if(dict[s[i]] >= left) left = dict[s[i]] + 1;
  			dict[s[i]] = i;
  			ans = max(ans, i - left + 1);
  		}
  		return ans;
    }
};