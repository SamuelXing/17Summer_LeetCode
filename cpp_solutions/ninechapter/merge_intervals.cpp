/*
* Given a collection of intervals, merge all overlapping intervals.

Example
Given intervals => merged intervals:

[                     [
  [1, 3],               [1, 6],
  [2, 6],      =>       [8, 10],
  [8, 10],              [15, 18]
  [15, 18]            ]
]

*/

/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */


class Solution {
public:
    /*
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    static bool cmp(const Interval& a, const Interval& b){
    	return (a.start < b.start);
    }

    vector<Interval> merge(vector<Interval> &intervals) {
        // write your code here
        vector<Interval> rst;
        if(intervals.empty()){
        	return rst;
        }

        sort(intervals.begin(),intervals.end(), cmp);
        rst.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++){
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






