#include <bits/stdc++.h>
using namespace std;

int main() {
	set<string> S;
	S.insert("abc"); S.insert("def"); S.insert("xyz");
	S.insert("abc");
	set<string>::iterator p;
	for(p = S.begin(); p != S.end(); p++) cout << *p << " ";
	cout << endl;
	
	string s1 = "def";
	auto r = S.find(s1);
	if(r == S.end())
	cout << "xau " << s1 << " does not exist" << endl;
	else
	cout << "xau " << s1 << " exists in S" << endl;
	
}
