/*

Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words. You may assume the dictionary does not contain duplicate words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".

*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int maxLength = getMaxLength(wordDict);
        vector<bool> canSegment(s.length()+1);
        canSegment[0] = true;
        for(int i=1; i<= s.length(); i++){
        	canSegment[i] = false;
        	for(int j = 1; j <= maxLength && j<=i; j++){
        		if(!canSegment[i-j])
        			continue;
        		string word = s.substr(i-j, j);
        		if(find(wordDict.begin(), wordDict.end(),word) != wordDict.end()){	
        			canSegment[i] = true;
        			break;
        		}
        	}
        }
        return canSegment[s.length()];
    }
private:
	int getMaxLength(vector<string>& wordDict){
		int maxLength = 0;
		for(int i=0; i< wordDict.size(); i++){
			if(wordDict[i].length() > maxLength)
				maxLength = wordDict[i].length();
		}
		return maxLength;
	}
};