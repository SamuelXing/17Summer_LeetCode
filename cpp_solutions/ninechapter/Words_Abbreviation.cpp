/*
*
* Given an array of n distinct non-empty strings, you need to generate minimal possible abbreviations for every word following rules below.

* Begin with the first character and then the number of characters abbreviated, which followed by the last character.
* If there are any conflict, that is more than one words share the same abbreviation, a longer prefix is used instead of only the first character until making the map from word to abbreviation become unique. In other words, a final abbreviation cannot map to more than one original words.
* If the abbreviation doesn't make the word shorter, then keep it as original.
*
*/

class Solution {
public:
    /*
     * @param dict: an array of n distinct non-empty strings
     * @return: an array of minimal possible abbreviations for every word
     */
    vector<string> wordsAbbreviation(vector<string> &dict) {
        // write your code here
    	int len = dict.size();
    	unordered_map<string, int> count;
    	vector<int> prefix(len);
    	vector<string> ans(len);

    	for(int i=0; i< len; i++){
    		prefix[i] = 1;
    		ans[i] = getAbbr(dict[i], prefix[i]);
    		count[ans[i]]++;
    	}

    	
    	while(true){
    		bool unique = true;
    		for(int i=0; i<len; i++){
    			if(count[ans[i]] > 1){
    				prefix[i]++;
    				ans[i] = getAbbr(dict[i], prefix[i]);
    				count[ans[i]]++;
    				unique = false;
    			}
    		}
    		if(unique)
    			break;
    	}

    	return ans;
    }

   string getAbbr(string s, int start){
   	if(start >= s.length() - 2){
   		return s;
   	}
   	string ans;
   	ans = s.substr(0, start) + to_string(s.length()-1-start) + s.back();
   	return ans;
   }
};