/*
* Find the contiguous subarray within an array (containing at least one number) which has the largest product.

* For example, given the array [2,3,-2,4], the contiguous subarray [2,3] has the largest product = 6.
*
**/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        int maxP = nums[0];
        int minP = nums[0];
        int p = A[0];

        for(int i=1; i<nums.size(); i++){
        	int t = maxP;
        	maxP = max(minP*nums[i], max(maxP*nums[i], nums[i]));
        	minP = min(t*nums[i], min(minP*nums[i], nums[i]));
        	p = max(maxP, p);
        }
        return p;
    }
};