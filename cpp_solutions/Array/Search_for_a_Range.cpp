/*
*
* Search for a range
* Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.
* 
* Notes: binary search
* 
**/

#include <vector>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target){
	vector<int> rst;
	// rule out edge cases
	if(nums.size() == 0){
		rst.push_back(-1);
		rst.push_back(-1);
		return rst;
	}

	int leftBound = searchLeftBound(nums, target);
	int rightBound =  searchRightBound(nums, target);

	rst.push_back(leftBound);
	rst.push_back(rightBound);
	return rst;
}

int searchLeftBound(vector<int>& nums, int target){
	int start = 0, end = nums.size() - 1;
	while(start + 1 < end){
		int mid = (start + end) / 2;

		if(nums[mid] == target){
			end = mid;
		}
		else if(nums[mid] < target){
			start = mid;
		}
		else{
			end = mid;
		}
	}

	if(nums[start] == target){ return start; }
	else if(nums[end] == target) {return end;}
	else {return -1; }
}

int searchRightBound(vector<int>& nums, int target){
	int start = 0, end = nums.size() - 1;
	while(start + 1 < end){
		int mid = (start + end) / 2;

		if(nums[mid] == target){
			start = mid;
		}
		else if(nums[mid] < target){
			start = mid;
		}
		else{
			end = mid;
		}
	}
	
	if(nums[end] == target) {return end;}
	else if(nums[start] == target){ return start; }
	else {return -1; }
}
