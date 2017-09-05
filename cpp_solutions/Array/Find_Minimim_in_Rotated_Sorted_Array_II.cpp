/*
*
* Follow up for "Find Minimum in Rotated Sorted Array":
* What if duplicates are allowed?
*
* Would this affect the run-time complexity? How and why?
* 
*/

#include<vector>
using namespace std;

int findMin(svector<int>& nums){
	int left = 0, right = nums.size()-1;

	while(left < right){
		int mid = (left + right)/2;

		if(nums[mid] > nums[right]){
			left = mid + 1;
		}else if(nums[mid] < nums[right]){
			right = mid;
		}else{
			right--;
		}
	}
	return nums[left];
}