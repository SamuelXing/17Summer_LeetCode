/*
* Given two rectangles, find if the given two rectangles overlap or not.

* l1: Top Left coordinate of first rectangle.
* r1: Bottom Right coordinate of first rectangle.
* l2: Top Left coordinate of second rectangle.
* r2: Bottom Right coordinate of second rectangle.

* l1 != r2 and l2 != r2
*
*/

class Solution {
public:
    /*
     * @param l1: top-left coordinate of first rectangle
     * @param r1: bottom-right coordinate of first rectangle
     * @param l2: top-left coordinate of second rectangle
     * @param r2: bottom-right coordinate of second rectangle
     * @return: true if they are overlap or false
     */
    bool doOverlap(Point &l1, Point &r1, Point &l2, Point &r2) {
        // write your code here
        // consider cases not overlap.
        if(r1.x < l2.x || l1.x >r2.x || r1.y > l2.y || l1.y < r2.y)
        	return false;
        else
        	return true;
    }
};
