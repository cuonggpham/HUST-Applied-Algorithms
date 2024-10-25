#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, k, s;
int cnt=0;


void Try(int i, int pos, int sum){
    if(i == k && sum == s){
        cnt++;
        return;
    }
    if(i >= k || sum >= s) return;
    for(int j=pos; j<=n; j++){
        Try(i+1, j+1, sum+j);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k >> s;
    Try(0, 1, 0);
    cout << cnt << endl;
}