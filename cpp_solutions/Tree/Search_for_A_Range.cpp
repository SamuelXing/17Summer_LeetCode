/*
	Given a sorted array of n integers, 
	find the starting and ending position of a given target value.

	If the target is not found in the array, return [-1, -1].

Example
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

*/

class Solution {
  /** 
   *@param A : an integer sorted array
   *@param target :  an integer to be inserted
   *return : a list of length 2, [index1, index2]
   */
public:
  vector<int> searchRange(vector<int> &A, int target) {
    // write your code here
    vector<int> ans;
    int ansl = -1;
    for (int l = 0, r = A.size() - 1; l <= r;) {
      int mid = l + (r - l) / 2;
      if (A[mid] > target) {
        r = mid - 1;
      }
      if (A[mid] < target) {
        l = mid + 1;
      }
      if (A[mid] == target) {
        ansl = mid;
        r = mid - 1;
      }
    }
    
    int ansr = -1;
    for (int l = 0, r = A.size() - 1; l <= r;) {
      int mid = l + (r - l) / 2;
      if (A[mid] > target) {
        r = mid - 1;
      }
      if (A[mid] < target) {
        l = mid + 1;
      }
      if (A[mid] == target) {
        ansr = mid;
        l = mid + 1;
      }
    }
    ans.push_back(ansl);
    ans.push_back(ansr);
    return ans;
  }
};
