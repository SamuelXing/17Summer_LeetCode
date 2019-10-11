#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

// input size: [1...200,000]
// solution 1: bruto-force, time complexity: O(n^3)
bool isValid(string& S, size_t i, size_t j) {
	int cnt = 1;
	for(size_t k = i+1; k <= j; k++) {
		if(S[k] == S[k-1]) cnt += 1;
		else cnt = 1;
		if(cnt > 2) return false;
	}

	return true;
}

int solution1(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    int ret = 0;
    for(size_t i = 0; i < S.size(); i++) {
    	for(size_t j = i; j < S.size(); j++) {
    		if(isValid(S, i, j)) {
    			ret = ret < (j - i +1 ) ? j - i + 1 : ret;
    		}
    	}
    }
    return ret;
}

// --------------------------------------------
// solution 2: time complexity: O(n)
int solution2(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    int ret = 1;

    size_t i = 0;
    size_t j = 1;
    int cnt = 1;
    size_t n = S.size();

    while(j < n) {
    	if(S[j] == S[j-1]) cnt += 1;
    	else cnt = 1;

    	if(cnt > 2) i = j - 1;
    	ret = ret < (j - i + 1 ) ? j - i + 1 : ret;

    	j++;
    }

    return ret;
}

int main() {
	string s1 = "baaaaaaabbabbb";
	string s2 = "babba";
	string s3 = "abaaa";
	string s4 = "baaabbabbb";
	string s5 = "aaaaaaa";

	cout << "Solution1:" << endl;
	cout << solution1(s1) << endl;
	cout << solution1(s2) << endl;
	cout << solution1(s3) << endl;
	cout << solution1(s4) << endl;
	cout << solution1(s5) << endl;
	
	cout << "Solution2:" << endl;
	cout << solution2(s1) << endl;
	cout << solution2(s2) << endl;
	cout << solution2(s3) << endl;
	cout << solution2(s4) << endl;
	cout << solution2(s5) << endl;
}

