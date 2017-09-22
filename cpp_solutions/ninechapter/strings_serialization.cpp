/*
Design an algorithm to encode a list of strings to a string. 
The encoded string is then sent over the network and is decoded back to the original list of strings.

Please implement encode and decode

Example
Given strs = ["lint","code","love","you"]
string encoded_string = encode(strs)

return `["lint","code","love","you"]｀ when you call decode(encoded_string)

*/

class Solution {
public:
    /**
     * @param strs a list of strings
     * @return encodes a list of strings to a single string
     */
    string encode(vector<string>& strs) {
        // Write your code here
        string rst;
        for(int i=0; i<strs.size(); i++){
        	string s = strs[i];
        	for(int j=0; j< s.size(); j++){
        		if(s[j] == ':')
        			rst += "::";
        		else
        			rst += s[j];
        	} 
        	rst += ":;";
        }
        return rst;
    }

    /**
     * @param str a string
     * @return dcodes a single string to a list of strings
     */
    vector<string> decode(string& str) {
        // Write your code here
    	vector<string> rst;
    	string word;
    	int i=0;
    	while(i < str.size()){
    		if(str[i] == ':'){
    			if(str[i+1] == ';'){
    				rst.push_back(word);
    				word = "";
    				i += 2;
    			}
    			else{
    				word += str[i+1];
    				i += 2;
    			}
    		}
    		else{
    			word += str[i];
    			i += 1;
    		}
    	}
    	return rst;
    }
};




