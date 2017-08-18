/* Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice? */
#include<vector>
#include<iostream>

int removeDuplicates(vector<int>& nums){
	if(nums.size() == 0)
	{
		return 0;
	}
	
	int j = 0;
	int cnt = 0;
	for(int i=1; i < nums.size(); i++)
	{
		if(nums[i] != nums[j]){  // if not duplicate
			cnt = 0; 		
			A[++j] = A[i];
		}
		else{ 										// if duplicate
			cnt++;
			if(cnt < 2){
				nums[++j] = nums [i];
			}
		}
	}
	return j+1;
}
