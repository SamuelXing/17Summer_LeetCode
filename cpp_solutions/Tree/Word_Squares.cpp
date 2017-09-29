/*
Given a set of words without duplicates, find all word squares you can build from them.

A sequence of words forms a valid word square if the kth row and column read the exact same string, where 0 ≤ k < max(numRows, numColumns).

For example, the word sequence ["ball","area","lead","lady"] forms a word square because each word reads the same both horizontally and vertically.

b a l l
a r e a
l e a d
l a d y

*/

class Solution {
public:
    /*
     * @param words: a set of words without duplicates
     * @return: all word squares
     */
    vector<vector<string>> wordSquares(vector<string> &words) {
        // write your code here
    	if(words.size() == 0)
    		return ans;
    	initPrefix(words);
    	wordLen = words[0].length();
    	dfs(0);
    	return ans;
    	
    }
private:
	// initialize hashMap, which is used to save the prefix-word relations
	void initPrefix(vector<string>& words){
		for(int i=0; i<words.size(); i++){
			string item = words[i];
			hash[""].push_back(item);
			for(int j=0; j< item.length(); j++)
				hash[item.substr(0, j+1)].push_back(item);
		}
	}

	// check nextword's prefix satisfy the rules or not
	bool checkPrefix(int l, string nextWord){
		for(int i=l+1; i< wordLen; i++){
			string prefix = "";
			for(int j=0; j < l; j++){
				prefix += squares[j][i];
			}
			prefix += nextWord[i];
			if(hash[prefix].size() == 0){
				return false;
			}
		}
		return true;
	}
	
	// searching 
	void dfs(int level){
		if(level == wordLen){
			ans.push_back(squares);
			return;
		}

		string pre;
		for (int i = 0; i < level; ++i)
		{
			/* code */
			pre += squares[i][level];
		}
		vector<string> w=hash[pre];

		for (int i = 0; i < w.size(); ++i)
		{
			/* code */
			if(!checkPrefix(level, w[i])){
				continue;
			}
			squares.push_back(w[i]);
			dfs(level+1);
			squares.pop_back();
		}
	}

private:
	int wordLen;
	unordered_map<string, vector<string>> hash;
	vector<string> squares;
	vector<vector<string>> ans;
};