#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

// time complexity: O(n)
int solution1(string &S) { 
	int ret = 0;

    size_t j = 1;
    int cnt = 1;
    size_t n = S.size();
    if(n == 1) return 0;

    while(j < n) {
    	if(S[j] == S[j-1]) {
    		cnt += 1;
    		if(j == n-1 && cnt > 2)
    			ret += cnt/3;
    	}
    	else{
    		if(cnt > 2) ret += cnt/3;
    		cnt = 1;
    	}
    	
    	j++;
    }

    return ret;
}

int main () {
	string s1 = "baaaaa";
	cout << solution1(s1) << endl;
	string s2 = "baaabbaabbba";
	cout << solution1(s2) << endl;
	string s3 = "baabab";
	cout << solution1(s3) << endl;
}