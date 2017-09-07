/*
* Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, 
* find the one that is missing from the array.
*
* Notes: a^(b^a) = b
**/
#include <vector>
using namespace std;

int missingNumber(vector<int>& nums)
{
	 int x = 0;
     for (int i = 0; i <= nums.size(); i++) x ^= i;
     for (auto n : nums) x ^= n;
     return x;
}