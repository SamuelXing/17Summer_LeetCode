/*

Given n points on a 2D plane, 
find the maximum number of points that lie on the same straight line.

*/

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

// calculate the gradient, use hashMap to save
class Solution {
public:
    /*
     * @param points: an array of point
     * @return: An integer
     */
    int maxPoints(vector<Point> &points) {
        // write your code here
        unordered_map<float, int> hashMap;
        int maxNum = 0;
        for(int i=0; i<points.size(); i++){
        	hashMap.clear();
        	hashMap[INT_MIN] = 0;
        	int duplicate = 1;
        	for(int j=0; j<points.size(); j++){
        		if(i == j) continue;
        		if(points[i].x == points[j].x && points[i].y == points[j].y){
        			duplicate++;
        			continue;
        		}
        		float k = points[i].x == points[j].x ? INT_MAX : (float)(points[j].y - points[i].y)/(points[j].x - points[i].x);
        		// pay attention to type casting !!!
        		//float k = (points[i].x == points[j].x)?INT_MAX:(float)((points[j].y-points[i].y)/(points[j].x - points[i].x));
        		hashMap[k]++;
        	}
        	unordered_map<float, int>::iterator it = hashMap.begin();
        	
        	for(; it != hashMap.end(); it++){
        		if(it->second + duplicate > maxNum)
        			maxNum = it->second + duplicate;
        	}
        }
        return maxNum;

    }
};