#include <bits/stdc++.h>
using namespace std;
int main() {
 stack<int> S;
 for(int i = 1; i <= 5; i++){
 S.push(i); cout << "PUSH " << i << endl;
 }
 while(!S.empty()){
 int e = S.top(); S.pop(); cout << "POP " << e << endl;
 }
}