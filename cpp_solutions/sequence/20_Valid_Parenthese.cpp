/*

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

*/

class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        // key, pay attention to this
        stack.push_back(' ');
        for(auto ch : s)
        {
            if(ch == '(' || ch == '{' || ch == '[' )
            {
                stack.push_back(ch);
            }
            if(ch == ')')
            {
                char pair = stack.back();
                if(pair == '(')
                {
                    stack.pop_back();
                }
                else
                    return false;
            }
            if(ch == '}')
            {
                char pair = stack.back();
                if(pair == '{')
                {
                    stack.pop_back();
                }
                else
                    return false;
            }
            if(ch == ']')
            {
                char pair = stack.back();
                if(pair == '[')
                {
                    stack.pop_back();
                }
                else
                    return false;
            }
        }
        if (stack.back() != ' ') {
            return false;
         }
    
        return true;
    }
};