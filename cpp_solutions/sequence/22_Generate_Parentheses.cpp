/*

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";
        dfs(ans, temp, 0, 0, n);
        return ans;
    }
    void dfs(vector<string>& ans, string temp, int leftP, int rightP, int n)
    {
        if(rightP == n)
        {
            ans.push_back(temp);
        }
        else if(leftP == n)
        {
            temp +=')';
            dfs(ans, temp, leftP, rightP+1, n);
        }
        else {
            if(leftP > rightP)
            {
                dfs(ans, temp+')', leftP, rightP+1, n);
            }
            // here
            dfs(ans, temp+'(', leftP+1, rightP, n);
        }
    }
};