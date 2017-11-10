/*
Write a function to find the longest common prefix string amongst an array of strings.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        
        string ans = "";
        for(int i=0; i< strs[0].length(); i++)
        {
            for(int j = 1; j<strs.size(); j++)
            {
                if(strs[j][i] != strs[0][i])
                    return ans;
            }
            ans += strs[0][i];
        }
        
        return ans;
    }
};