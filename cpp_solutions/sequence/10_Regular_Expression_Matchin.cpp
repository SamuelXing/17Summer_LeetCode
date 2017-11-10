/*

Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true

*/

// How to think about this question?
// 1, start from the simplest one.
// ruling out edge cases, thinking about what if s.len = 0 or p.len = 0
// 2, for general cases
// 

class Solution {
public:
    bool isMatch(string s, string p) {
        // if s.length() == 0, then p.length() == 0 for follow X*X*
        if(s.length() == 0)
        {
            // key
            if(p.length() & 1 ) return false;
            else
            {
                for(int i=1; i< p.length(); i+=2)
                {
                    if(p[i] != '*')
                        return false;
                }
            }
            return true;
        }
        
        if(p.length() == 0) 
            return false;
        
        if(p.length() > 1 && p[1] == '*')
        {
            if(s[0] == p[0] || p[0] == '.')
            {
                // isMatch(s.substr(1), p) : "aaaabb", "a*bb"; isMatch(s, p.substr(2)): "abb", "c*abb";
                return isMatch(s.substr(1), p) || isMatch(s, p.substr(2));
            }else
            {
                return isMatch(s, p.substr(2));
            }
        }
        else // s.length() >= 1 && (p.length() == 1 || (p.length() > 1 && p[1]!='*') )
        {
            if (p[0] == '.' || s[0] == p[0]) {
                return isMatch(s.substr(1), p.substr(1));
            } 
            else return false;
        }
        
    }
};
