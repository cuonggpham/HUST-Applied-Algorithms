#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int a[100][100], n;

void input(){
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> a[i][j];
        }
    }
}

void Try(int i, int j, string s){
    if(i==n && j==n){
        cout << s << endl;
    }
    if(i+1<=n && a[i+1][j]==1){
        s+="D";
        Try(i+1, j, s);
        s.pop_back();
    }
    if(j+1<=n && a[i][j+1]==1){
        s += "R";
        Try(i, j+1, s);
        s.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    Try(1, 1, ""); 
}

// 4
// 1 1 0 1
// 1 1 1 1
// 1 0 1 1
// 1 1 1 1
// output:
// DDDRRR
// DRRDDR
// DRRDRD
// DRRRDD
// RDRDDR
// RDRDRD
// RDRRDD