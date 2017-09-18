/*
* Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

* For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
* the contiguous subarray [4,-1,2,1] has the largest sum = 6.
*
*/

// Solution 1: Greedy
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return 0;

     	int maxSum = INT_MIN, sum = 0;
     	for (int i = 0; i < nums.size(); ++i)
     	{
     		sum += nums[i];
     		maxSum = max(maxSum, sum);
     		sum = max(sum, 0);
     	}

     	return maxSum;
    }
};

// Solution 2: Prefix Sum
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return 0;

     	int maxSum =INT_MIN, sum = 0, minSum = 0;
     	for (int i = 0; i < nums.size(); ++i)
     	{
     		sum += nums[i];
     		maxSum = max(maxSum, sum - minSum);
     		minSum = min(minSum, sum);		
     	}	
    }
};

// Solution 3: Divide and Conquer
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return 0;

     	int n = nums.size();
     	int global[2];
     	int local[2];

     	global[0] = nums[0];
     	local[0] = nums[0];
     	for(int i=1; i<n; i++){
     		local[i%2] = max(nums[i], local[(i - 1) % 2] + nums[i]);
     		global[i % 2] = max(local[i % 2], global[(i - 1) % 2]);  
     	}

     	return global[(n-1) % 2];  
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return divide(nums, 0, nums.size() - 1, INT_MIN);
    }

    int divide(vector<int>& A, int left, int right, int tmax) {
        if(left > right) {
            return INT_MIN;
        }

        int mid = left + (right - left) / 2;
        int lmax = divide(A, left, mid - 1, tmax);
        int rmax = divide(A, mid + 1, right, tmax);

        tmax = max(tmax, lmax);
        tmax = max(tmax, rmax);

        int sum = 0;
        int mlmax = 0;
        for(int i = mid - 1; i >= left; i--) {
            sum += A[i];
            mlmax = max(mlmax, sum);
        }

        sum = 0;
        int mrmax = 0;
        for(int i = mid + 1; i <= right; i++) {
            sum += A[i];
            mrmax = max(mrmax, sum);
        }

        tmax = max(tmax, A[mid] + mlmax + mrmax);
        return tmax;
    }
};

