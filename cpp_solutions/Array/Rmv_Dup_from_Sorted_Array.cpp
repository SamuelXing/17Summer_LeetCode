#include<iostream>
#include<vector>

int removeDuplicates(std::vector<int>& nums)
{
	if(nums.empty()) return 0;

	int index=1;
	for(int i=1;i<nums.size();i++)
	{
		if(nums[i]!=nums[index-1])
			nums[index++] = nums[i];
	}
	return index;
}

int main()
{
	std::vector<int> test1={1,1,2};
	int result1=removeDuplicates(test1);
	std::cout<< "result1: "<< result1<<"\n";
	for(int i=0; i< test1.size();i++)
	{
			std::cout<<test1[i]<<",";
	}
	std::cout<<"\n";
	return 0;
}
