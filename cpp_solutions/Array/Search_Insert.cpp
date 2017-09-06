/*
* 
* Given a sorted array and a target value, return the index if the target is found.
* If not, return the index where it would be if it were inserted in order.
*
**/

#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target)
{
	if(nums.size() == 0){
		return 0;
	}

	int start = 0, end = nums.size() - 1;

	while(start + 1 < end)
	{
		int mid = (start + end)/2;
		if(nums[mid] < target){
			start = mid;
		}
		else if(nums[mid] > target){
			end = mid;
		}
		else
		{
			return mid;
		}
	} 

	if(nums[start] >= target){
		return start;
	}
	if(nums[end] >= target){
		return end;
	}

	return nums.size();
}