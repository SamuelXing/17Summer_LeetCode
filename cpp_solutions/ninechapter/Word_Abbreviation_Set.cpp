/*
An abbreviation of a word follows the form . Below are some examples of word abbreviations:

a) it                      --> it    (no abbreviation)

     1
b) d|o|g                   --> d1g

              1    1  1
     1---5----0----5--8
c) i|nternationalizatio|n  --> i18n

              1
     1---5----0
d) l|ocalizatio|n          --> l10n


Assume you have a dictionary and given a word, 
find whether its abbreviation is unique in the dictionary. 
A word's abbreviation is unique if no other word from the dictionary has the same abbreviation.

*/

class ValidWordAbbr {
private:
	unordered_map<string, int> dict;
	unordered_map<string, int> abbreviation;
public:
    // @param dictionary a list of word
    ValidWordAbbr(vector<string> dictionary) {
        // Write your code here
        if(dictionary.empty()) return;

        for(auto item : dictionary){
        	dict[item]++;

        	if(item.length()<=2)
        		abbreviation[item] ++;
        	else
        		abbreviation[item[0]+to_string(item.length()-2)+item[item.length()-1]]++;
        }
    }

    /**
     * @param word a string
     * @return true if its abbreviation is unique or false
     */
    bool isUnique(string& word) {
        // Write your code here
        if(word.length()<=2)
        	return abbreviation[word] == dict[word];
        else
        	return abbreviation[word[0]+to_string(word.length()-2)+word[word.length()-1]] == dict[word];
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param = obj.isUnique(word);
 */