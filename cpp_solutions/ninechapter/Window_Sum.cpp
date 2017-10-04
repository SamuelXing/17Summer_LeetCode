/*

Given an array of n integer, and a moving window(size k), 
move the window at each iteration from the start of the array, 
find the sum of the element inside the window at each moving.

Example
For array [1,2,7,8,5], moving window size k = 3. 
1 + 2 + 7 = 10
2 + 7 + 8 = 17
7 + 8 + 5 = 20
return [10,17,20]

*/

// Solution 1:
class Solution {
public:
    /*
     * @param nums: a list of integers.
     * @param k: length of window.
     * @return: the sum of the element inside the window at each moving.
     */
    vector<int> winSum(vector<int> &nums, int k) {
        // write your code here
       	vector<int> sum;
       	if(nums.size()==0)
       	    return sum;
       	for(int i=0; i<nums.size()-k+1; i++){
       		int winSum = 0;
       		for(int j=i; j<= i+k-1; j++){
       			winSum+=nums[j];
       		}
       		sum.push_back(winSum);
       	}
       	return sum;
    }
};



// Solution 2:
class Solution {
public:
    /*
     * @param nums: a list of integers.
     * @param k: length of window.
     * @return: the sum of the element inside the window at each moving.
     */
    vector<int> winSum(vector<int> &nums, int k) {
        // write your code here
       	vector<int> sum;
       	if(nums.size()==0)
       	    return sum;
       	sum.resize(nums.size()-k+1, 0);
       	for(int i=0; i< k ;i++){
       		sum[0] += nums[i];
       	}
       	for(int i=k; i< nums.size(); i++){
       		sum[i-k+1] = sum[i-k] + nums[i] - nums[i-k];
       	}
       	return sum;
    }
};




