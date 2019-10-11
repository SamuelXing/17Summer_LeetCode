#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

int sum_digits(int a) {
	int ret = 0;
	while(a){
		ret += a % 10;
		a /= 10;
	}

	return ret;
}

int solution(vector<int>& A) {
	unordered_map<int, int> m;
	int ret = -1;

	for(auto a : A) {
		int sum_of_digits = sum_digits(a);
		if(m.find(sum_of_digits) != m.end()) {
			ret = max(ret, a + m[sum_of_digits]);
			m[sum_of_digits] = max(a, m[sum_of_digits]);
		}
		else 
			m[sum_of_digits] = a;
	}

	return ret;
}

int main() {
	vector<int> A1 = {51, 71, 17, 42};
	cout << solution(A1) << endl;
	vector<int> A2 = {42, 33, 60};
	cout << solution(A2) << endl;
	vector<int> A3 = {51, 32, 43};
	cout << solution(A3) << endl;
}