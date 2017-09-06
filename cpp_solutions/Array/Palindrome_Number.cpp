/*
* Determine whether an integer is a palindrome. Do this without extra space.
* 
* Notes: Mathmatic calculation
**/

bool isPalindrome(int x){
	if(x < 0) return false;
	long rev = 0, temp = 0;
	temp = x;

	while(temp){
		rev = rev*10 + temp % 10;
		temp = temp / 10;
	}

	return rev == x;
}