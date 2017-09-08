/*
* Given an integer, write a function to determine if it is a power of two.
*
**/

bool isPowerofTwo(int n)
{
	if(n < 0) return false;
	bool flag=false;
	while(n>0)
	{
		if(n & 1){
			if(flag){return false;}
			else{flag=true;}				
		}
		n>>=1;
	}
	return flag;
}

// Solution 2
// bool isPowerofTwo(int n)
// {
// 	if(n < 0) return false;
// 	return (n & (n-1)) == 0;
// }
