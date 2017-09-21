/*
* A mirror number is a number that looks the same when rotated 180 degrees (looked at upside down).

* Write a function to determine if a number is mirror. The number is represented as a string.
*
**/

class Solution {
public:
    /*
     * @param num: a string
     * @return: true if a number is strobogrammatic or false
     */
    bool isStrobogrammatic(string &num) {
        // write your code here
        vector<int> hash(256, 0);
        hash['0'] = '0';
        hash['1'] = '1';
        hash['6'] = '9';
        hash['8'] = '8';
        hash['9'] = '6';
        
        
        int i=0, j = num.size()-1;
        for(int i=0; i< num.length(); i++){
            int j = num.length() - i -1;
            if(hash[num[i]]!=num[j]) return false;
        }
        return true;
    }
};