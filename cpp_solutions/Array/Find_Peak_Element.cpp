/*
* A peak element is an element that is greater than its neighbors.
*
* Note: binay search
**/

int findPeakElement(vector<int>& nums)
{
	 int start = 0, end = nums.size() - 1, mid=0;
	 
	 while(start<=end){
        mid=(start+end)/2; 
        // important
		if((mid==0||nums[mid]>nums[mid-1]) &&( nums[mid]>nums[mid+1]||mid==nums.size() - 1)){
			return mid;
		}
		else if(mid > 0 && nums[mid]<nums[mid-1]){
			end = mid-1;
		}
		else
		{
			start = mid + 1;
		}
	}
	return mid;
}