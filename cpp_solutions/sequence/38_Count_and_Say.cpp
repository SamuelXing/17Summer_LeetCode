/*

The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

*/

// Note: hard to think
// python solution

class Solution {
public:
    string countAndSay(int n) {
        string s="1";
        
        while(--n)
        {
            s = generate(s);
        }
        
        return s;
    }
private:
    string generate(string s)
    {
        string temp;
        int j=0;
        for(int i=0; i<s.size(); i+=j)
        {
            for(j = 0; i+j < s.size(); j++)
            {
                if(s[i] != s[i+j]) {
                    break;
                } 
            }
            temp = temp + to_string(j) + s[i];
        }
        return temp;
    }
};