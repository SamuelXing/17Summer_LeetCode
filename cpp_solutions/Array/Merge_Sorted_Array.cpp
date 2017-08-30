/*
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
 * 
 * */

#include<vector>

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
	int i = m + n -1;
	int j = m - 1;
	int k = n - 1;
	
	while( i >= 0){
		if(j >= 0 && k >=0 ){
			if(nums1[j] > nums2[k]){
				nums1[i] = nums1[j];
				j--;
			}else{
				nums1[i] = nums2[k];
				k--;
			}
		}
		else if( j>=0 ){
			nums1[i] = nums1[j];
			j--;
		}
		else if( k>=0 ){
			nums1[i] = nums2[k];
			k--;
		}
		i--;
	}
}
