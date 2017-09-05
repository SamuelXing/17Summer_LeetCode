/*
* Given n non-negative integers representing the histogram's bar
* height where the width of each bar is 1, find the area of largest rectangle in the histogram.
* 
* Notes: Using a stack to record the increasing segaments in the sequences.
*
**/

#include <vector>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int>& height)
{
	if(height.size() == 0) return 0;
	// result
	int rst = 0;
	// counter
	int i = 0;
	stack<int> s;
	// push 0 back to the height array, in order to continue the counting until the end last element
	height.push_back(0);
	

	while(i < height.size())
	{
		if(s.empty() || !s.empty() && height[i] > height[s.top()]){
			s.push(i);
			i++;
		}
		else{
			int tmp = s.top();
			s.pop();
			rst = max(rst, height[tmp] * (s.empty()?i:i-s.top()-1));
		}
	}
	return rst;
}