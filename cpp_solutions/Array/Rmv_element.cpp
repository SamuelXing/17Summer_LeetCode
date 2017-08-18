/*Given an array and a value, remove all instances of that > value in place and return the new length.
The order of elements can be changed. It doesn't matter what you leave beyond the new length. */

#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
  int removeElement(vector<int>& nums, int val) {
		int i=0;
		int j=0;
		for(i=0; i< nums.size(); i++)
		{
			if(nums[i] == val){
					continue;
			}

			nums[j] = nums[i];
			j++;
		}
		return j;
	}
};

int main()
{
	Solution* solution = new Solution();
	std::vector<int> vec = {3, 2, 2, 3};
	int j = solution->removeElement(vec, 3);
	std::cout << "result:" << j <<"\n";
	delete solution;
	for(int i=0; i< j; i++){
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}
