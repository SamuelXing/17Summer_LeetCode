/*

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

*/
class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> stack;
        for(int i=0; i< s.length(); i++)
        {
            if(s[i] == '(')
            {
                stack.push_back(1);
            }
            else  // s[i] == ')'
            {
                if(stack.size() > 0 && stack[stack.size()-1]==1)
                {
                    stack[stack.size()-1] = 2;
                }else if(stack.size() > 1 && stack[stack.size()-1] > 1 && stack[stack.size()-2] == 1) // "((( )))"
                {
                    stack[stack.size()-2] = stack[stack.size()-1] + 2;
                    stack.pop_back();
                }
                else // "))))"
                {
                    stack.push_back(-1);
                }
                
                while(stack.size() > 1 && stack[stack.size()-1] > 1 && stack[stack.size()-2] > 1)
                {
                    stack[stack.size()-2] += stack[stack.size()-1];
                    stack.pop_back();
                }
            }
        }
        
        int rst = 0;
        for(int i=0; i< stack.size(); i++)
        {
            if(stack[i] < 2)
            {
                continue;
            }
            rst = max(rst,stack[i]);
        }
        return rst;
    }
};