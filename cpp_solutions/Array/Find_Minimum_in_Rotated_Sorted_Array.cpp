/*
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to u
 * beforehand.
 *
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 * Find the minimum element.
 *
 * */

#include<vector>
using namespace std;

int findMin(vector<int>& nums){
	int front = 0, end = nums.size() - 1;

	while(nums[front] > nums[end])
	{
		int mid = (front + end)/2;
		if(nums[mid] >= nums[front] && nums[mid] > nums[end])
			front = mid + 1;
		else
			end = mid;
	}
	return nums[front];
}

