/*

There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5

TAG:
Array, binary search, Divide and conquer.

*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalSize = nums1.size()+ nums2.size();
        double rst;

        if(totalSize & 1){
        	rst = findKth(nums1, nums2, 0,0, totalSize/2+1);
        }
        else{
        	rst = (findKth(nums1, nums2, 0, 0, totalSize/2+1) + 
        		findKth(nums1, nums2, 0, 0, totalSize/2))/2.0;
        }
        return rst;
    }	
private:
	double findKth(vector<int> nums1, vector<int> nums2, int pos1, int pos2, int k){
		if(pos1 >= nums1.size()){
			return nums2[pos2 + k - 1];
		}
		if(pos2 >= nums2.size()){
			return nums1[pos1 + k -1];
		}
		if(k == 1) return min(nums1[pos1], nums2[pos2]);
		int key1 = pos1 + k/2 - 1 >= nums1.size()? INT_MAX : nums1[pos1 + k/2 - 1];
		int key2 = pos2 + k/2 - 1 >= nums2.size()? INT_MAX : nums2[pos2 + k/2 -1];
		if(key1 < key2){
			return findKth(nums1, nums2, pos1+k/2, pos2, k - k / 2);
		}
		else{
			return findKth(nums1, nums2, pos1, pos2+k/2, k - k / 2);
		}
	}
};

