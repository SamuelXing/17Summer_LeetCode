/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

Note:
You can assume that you can always reach the last index.

*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int cur = 0;
        int next = 0;
        int minStep = 0;
        if(nums.size()==1) return 0;
        while(cur<=next)
        {
        	minStep++;
        	int curNext = next;
        	for(int i=cur; i<=curNext;i++){
        		if((nums[i]+i) >= (nums.size()-1))
        			return minStep;
        		if(nums[i]+i > next)
        			next = nums[i]+i;
        	}
        	cur = cur+1;
        }
        return 0;
    }
};
