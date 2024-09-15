#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> V;
	V.push_back(1); V.push_back(2); //push_back(val)
	for(int i = 3; i <= 10; i++) V.push_back(i);
	for(int i = 0; i < V.size(); i++) cout << V[i] << " ";
	cout << endl;
	
//	for(int e : V) cout << e;
	
	V.erase(V.begin(), V.begin() + 3); //erase(begin, end)
	for(int i = 0; i < V.size(); i++) cout << V[i] << " ";
	cout << endl;
}
//1 2 3 4 5 6 7 8 9 10
//4 5 6 7 8 9 10
