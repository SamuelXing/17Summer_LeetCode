/*

You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).

*/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> rst;
        if(words.size() == 0) return rst;
        
        unordered_map<string, int> dict;
        for(int i=0; i< words.size(); i++)
        {
            if(dict.find(words[i]) == dict.end())
                dict[words[i]] = 1;
            else
                dict[words[i]]++;
        }
        
        int wSize = words[0].length();
        for(int i=0; i< wSize; i++)
        {
            int wCnt = 0;
            unordered_map<string, int> slideWin;
            for(int j=i; j + wSize<= s.length(); j+=wSize)
            {
                string curWord = s.substr(j, wSize);
                if(dict.find(curWord)==dict.end())
                {
                    slideWin.clear();
                    wCnt=0;
                }
                else
                {
                    wCnt++;
                    if(slideWin.find(curWord) == slideWin.end())
                    {
                        slideWin[curWord] = 1;
                    }
                    else
                    {
                        slideWin[curWord]++;
                    }
                    
                    while(dict[curWord]< slideWin[curWord])
                    {
                        string rmWord = s.substr(j-(wCnt-1)*wSize, wSize);
                        slideWin[rmWord]--;
                        wCnt--;
                    }
                }
                
                if(wCnt == words.size())
                {
                    rst.push_back(j - (wCnt-1)*wSize);
                }
            }
        }
        
        return rst;
    }
};