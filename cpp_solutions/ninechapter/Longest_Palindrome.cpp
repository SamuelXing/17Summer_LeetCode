/*
Given a string which consists of lowercase or uppercase letters, 
find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Example
Given s = "abccccdd" return 7

One longest palindrome that can be built is "dccaccd", whose length is 7.

*/

// solution 1: hashmap
class Solution {
public:
    /*
     * @param s: a string which consists of lowercase or uppercase letters
     * @return: the length of the longest palindromes that can be built
     */
    int longestPalindrome(string s) {
        // write your code here
        unordered_map<char, int> hash;
        for(int i=0; i< s.length(); i++){
        	hash[s[i]]++;
        }

        int one = 0;
        int ans = 0;
        for(auto it = hash.begin(); it!=hash.end(); it++){
        	if((it->second)%2) 
        		one = 1;
        	ans += (it->second)/2*2;
        }
        return ans+one;
    }
};


// solution 2: set
class Solution {
public:
    /*
     * @param s: a string which consists of lowercase or uppercase letters
     * @return: the length of the longest palindromes that can be built
     */
    int longestPalindrome(string s) {
        // write your code here
        set<char> single;
        for(auto c: s){
        	set<char>::iterator it=single.find(c);
        	if(it!=single.end()) single.erase(it);
        	else
        		single.insert(c);
        }

        int remove = single.size();
        if(remove > 0)
        	remove -= 1;
        return s.length() - remove;
    }
};











