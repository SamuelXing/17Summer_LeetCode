// 一个字符串，里面有字母（大写和小写），找同时出现过大小写的字母中，字典序最大的那个。
#include<iostream>
#include<string>
#include<vector>

using namespace std;

char findDictOrd(string str) {
	int n = str.length();
	if(n == 0) return '\0';
	
	vector<int> m(n, 0);
	for(auto c : str) {
		if((isupper(c) && m[c-'A'] == 0) || (isupper(c) && m[c-'A'] == -1)) 
			m[c-'A'] += 2;
		if((islower(c) && m[c-'a'] == 0) || (islower(c) && m[c-'a'] == 2)) 
			m[c-'a'] -= 1;
	}
	
	for(int i = 0; i < 26; i++) {
		if(m[i] == 1) return 'a'+i;
	}
	return '\0';
}

int main() {
	cout << findDictOrd(string("abdcDa")) << endl;
	cout << findDictOrd(string("aCbdcDa")) << endl;
	cout << findDictOrd(string("")) << endl;
	cout << findDictOrd(string("aaaaaaaa")) << endl;
	
	return 0;
}