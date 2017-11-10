/*

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

*/

class Solution {
public:
    string convert(string s, int numRows) {
        if(s.length() <= numRows || numRows == 1) return s;
        int index = 0, steps = (numRows-1)*2, len = s.length();
        char rst[len];
        for(int i=0; i< numRows; i++)
        {
            int intervals = steps - (i*2);
            for(int j=i; j<len; j+=steps)
            {
                rst[index] = s[j];       
                index ++;
                if((intervals < steps) && (j + intervals < len) && (intervals > 0) && (index<len))
                {
                    rst[index] = s[j+intervals]; 
                    index++;
                }
            }
        }    
        return rst;
    }
};