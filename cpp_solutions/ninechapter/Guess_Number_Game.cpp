/*
* We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number is higher or lower.

You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):

Example
n = 10, I pick 4 (but you don't know)

Return 4. Correct !

*/

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    /**
     * @param n an integer
     * @return the number you guess
     */
    int guessNumber(int n) {
        // Write your code here
        int start = 1, end = n;
        while(start <= end){
        	int mid = start+(end-start)/2;
        	if(guess(mid) == 0) return mid;
        	if(guess(mid) == -1) end = mid-1;
        	if(guess(mid) == 1)  start = mid+1;
        }
    }
};