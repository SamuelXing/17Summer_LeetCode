/*
* Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
* determine if the input string is valid.
*
**/
// Notes: at first, initialize a stack by pushing back ' ', in case of "}}}{{{"
class Solution {
public:
    /*
     * @param s: A string
     * @return: whether the string is a valid parentheses
     */
    bool isValidParentheses(string &s) {
        // write your code here
    	if(s.size()<=1) return false;
    	vector<char> stack;
    	stack.push_back(' ');
    	for(int i=0; i<s.size(); i++){
    		if(s[i]=='(' || s[i] == '[' || s[i] = '{')
    			stack.push_back(s[i]);
    		if(s[i] == ')'){
    			if(stack.back() != '(') return false;
    			stack.pop_back();
    		}
    		if(s[i] == ']'){
    			if(stack.back() != '[') return false;
    			stack.pop_back();
    		}
    		if(s[i] == '}'){
    			if(stack.back() != '{') return false;
    			stack.pop_back();
    		}
    	}
    	if(stack.back()==' ')
    	    return true;
    	else
    	    return false;
    }
};