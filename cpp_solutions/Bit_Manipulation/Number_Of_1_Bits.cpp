/*
* Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).
*
**/

int hammingWeight(uint32_t n){
	int count =0;
	while(n>0){
		count += n&1;
		n>>=1;
	}
	return count;
}

// Solution 2
// int hammingWeight(int n) {
//         if (n == 0) {
//             return 0;
//         }
        
//         int count = 1;
//         while ((n & (n - 1)) != 0) {
//             n &= n-1;
//             count++;
//         }
//         return count;
//  }