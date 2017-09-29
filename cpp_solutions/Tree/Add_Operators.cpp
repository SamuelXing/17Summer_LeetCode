/*
Given a string that contains only digits 0-9 and a target value, 
return all possibilities to add binary operators (not unary) +, -, or * 
between the digits so they evaluate to the target value.

Example
"123", 6 -> ["1+2+3", "1*2*3"] 
"232", 8 -> ["2*3+2", "2+3*2"]
"105", 5 -> ["1*0+5","10-5"]
"00", 0 -> ["0+0", "0-0", "0*0"]
"3456237490", 9191 -> []

*/
class Solution {
public:
    /*
     * @param num: a string contains only digits 0-9
     * @param target: An integer
     * @return: return all possibilities
     */
    vector<string> addOperators(string &num, int target) {
        // write your code here
        this->num = num;
        this->target = target;
        dfs("", 0, 0, 0);
        return ans;
    }
private:
	string num;
	int target;
	vector<string> ans;
	void dfs(string str, int pos, long long sum, long long lastF){
		if(num.length()==pos)
		{
			if(sum == target){
				ans.push_back(str);
			}
			return;
		}

		for(int i=pos; i< num.size(); i++){
			string curNumS = num.substr(pos, i-pos+1);
			long long curNum = stoll(curNumS);

			if(pos == 0){
				dfs(curNumS, i+1, curNum, curNum);
			}else{
				dfs(str+"*"+curNumS, i+1,  sum - lastF + lastF * curNum, lastF * curNum);
				dfs(str+"+"+curNumS, i+1,  sum+curNum, curNum);
				dfs(str+"-"+curNumS, i+1,  sum-curNum, -curNum);
			}

			if(num[pos] == '0'){
				break;
			}
		}
	}
};