/*
 * Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.
 *
 * You may assume the integer do not contain any leading zero, except the number 0 itself.
 *
 * The digits are stored such that the most significant digit is at the head of the list.
 * */

#include<iostream>
#include<vector>

using namespace std;

vector<int> plusOne(vector<int>& digits){
	vector<int> res(digits.size(), 0);
	int sum = 0;
	int one =1;
	for(int i = digits.size() - 1; i>=0; i--){
		sum = one + digits[i];
		one = sum / 10;
		res[i] = sum % 10;
	}
	
	if(one > 0){
		res.insert(res.begin(), one);
	}
	return res;
}

