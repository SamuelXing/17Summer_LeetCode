/*

Given a digit string excluded 01, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Example
Given "23"

Return ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]

*/

class Solution {
public:
	const vector<string> keyboard = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs","tuv", "wxyz"};
    /*
     * @param digits: A digital string
     * @return: all posible letter combinations
     */
    vector<string> letterCombinations(string &digits) {
        // write your code here
    	vector<string> rst;
    	if(digits.size() == 0) return rst;
		dfs(rst, 0, "", digits);
		return rst;	
    }

private:
	void dfs(vector<string>& rst, int cur, string path, const string& digits){
		if(cur == digits.size()){
			rst.push_back(path);
			return;
		}
		for(auto c: keyboard[digits[cur] - '0']){
			dfs(rst, cur+1, path+c, digits);
		}
	}
};