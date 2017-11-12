/*

Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1

*/

class Solution {
public:
     int strStr(string source, string  target) {
        int i, j, lenh = source.length(), lenn =  target.length();
        if (lenn == 0)  return 0;
        for (i = 0; i <= lenh - lenn; i++) {
            for (j = 0; j < lenn; j++) 
                if (source[i + j] !=  target[j]) break;
            if (j == lenn)  return i;
        }
        return -1;
    }
};