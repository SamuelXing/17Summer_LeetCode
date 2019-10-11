// 一串小写字符，删除‍‌‍‌‍‍‍‍‌‍‍‍‌‌‍‌‌‍‍一些字符，使得每个字符出现的次数都不一样，返回最少的删除个数。
#include<iostream>
#include<string>
#include<unordered_map>
#include<unordered_set>

using namespace std;

int deleteChar(string str){
	if(str.empty()) return 0;
	unordered_map<int, int> m;
	for(auto ch : str)
		m[ch-'a']++;

	unordered_set<int> s;
	for(auto it = m.begin(); it != m.end(); it++)
		s.insert(it->second);
	
	return m.size() - s.size();
}

int main() {
	cout << deleteChar("aa") << endl;
	cout << deleteChar("aab") << endl;
	cout << deleteChar("aabc") << endl;
	cout << deleteChar("aabb") << endl;
	cout << deleteChar("") << endl;
}