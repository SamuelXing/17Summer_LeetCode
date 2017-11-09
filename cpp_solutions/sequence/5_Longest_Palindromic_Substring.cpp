/*

Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb"

TAG:
string

*/

class Solution {
public:
    string longestPalindrome(string s) {
        string str = "", ans ="";
        int maxLen = -1, cnt;
        
        for(int i=0; i< s.length(); i++)
        {
            str += "*";
            str += s[i];
        }
        str += "*";
        
        for(int i=1; i<str.length(); i++)
        {
            cnt = 0;
            while((i-cnt>=0) && (i+cnt < str.length()) && (str[i-cnt] == str[i+cnt]))
                cnt ++;
            cnt -- ;
            if(maxLen < cnt)
            {
                maxLen = cnt;
                ans = s.substr((i-cnt)/2, (i+cnt)/2-(i-cnt)/2);
            }
        }
        return ans;
    }
};