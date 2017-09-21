/*
* Given a non-empty string word and an abbreviation abbr, 
* return whether the string matches with the given abbreviation.

* A string such as "word" contains only the following valid abbreviations:
*
**/

class Solution {
public:
    /*
     * @param word: a non-empty string
     * @param abbr: an abbreviation
     * @return: true if string matches with the given abbr or false
     */
    bool validWordAbbreviation(string word, string abbr) {
        // write your code here
        int i = 0, j = 0;
        while(i < word.size() && j < abbr.size()){
        	if(abbr[j]>='0' && abbr[j]<='9'){
        		if(abbr[j] == '0')
        			return false;
        		int val = 0;
        		while(j < abbr.size() && '0' <= abbr[j] && '9'>= abbr[j]){
        			val = val*10 + abbr[j] - '0';
        			j++;
        		}
        		i += val;

        	}
        	else{
        		if(word[i++] != abbr[j++]){
        			return false;
        		}
        	}
        }

        if( i == word.size() && j == abbr.size())
        	return true;
        else
        	return false;

    }
};