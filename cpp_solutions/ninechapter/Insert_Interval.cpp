/*
* Given a non-overlapping interval list which is sorted by start point.
* 
* Insert a new interval into it, make sure the list is still in order and non-overlapping (merge intervals if necessary).
*
*/

/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // write your code here
       vector<Interval> rst;

       int pos = 0;
       for(;pos < intervals.size() && intervals[pos].start < newInterval.start; pos++){}
       intervals.insert(intervals.begin()+pos, newInterval);

   	   rst.push_back(intervals[0]);
   	   for(int i=1; i< intervals.size(); i++){
   	   		if(rst.back().end >= intervals[i].start){
   	   			rst.back().end = max(rst.back().end, intervals[i].end);
   	   		}
   	   		else{
   	   			rst.push_back(intervals[i]);
   	   		}
   	   }
   	   return rst;
    }
};

