/*
* Given a sorted integer array where the range of elements are in the inclusive range [lower, upper], 
* return its missing ranges.

Example
Given nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99
return ["2", "4->49", "51->74", "76->99"].

*/
class Solution {
public:
    /**
     * @param nums a sorted integer array
     * @param lower an integer
     * @param upper an integer
     * @return a list of its missing ranges
     */
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        // Write your code here
        vector<string> rst;
        if(nums.empty()) {
        	addRange(rst, lower, upper);
        	return rst;
        }

        addRange(rst, lower, (long long)nums[0]-1);

        for(int i=1; i<nums.size(); i++){
        	addRange(rst, (long long)nums[i-1]+1, (long long)nums[i]-1);
        }
        addRange(rst, (long long)nums[nums.size()-1]+1, upper);

        return rst;
    }
private:
	void addRange(vector<string>& rst, long long left, long long right){
		if(left > right)
			return;
		if(left == right)
			rst.push_back(to_string(left));
		else
			rst.push_back(to_string(left)+"->"+to_string(right));
	}
};