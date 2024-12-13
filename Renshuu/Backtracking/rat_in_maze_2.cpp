#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int a[100][100], n, check=0;

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
        check = 1;
        cout << s << endl;
    }
    if(i+1<=n && a[i+1][j]==1){
        s+="D";
        a[i+1][j]=0;
        Try(i+1, j, s);
        a[i+1][j]=1;
        s.pop_back();
    }
    if(j-1>=0 && a[i][j-1]==1){
        s+="L";
        a[i][j-1]=0;
        Try(i, j-1, s);
        a[i][j-1]=1;
        s.pop_back();
    }
    if(j+1<=n && a[i][j+1]==1){
        s += "R";
        a[i][j+1]=0;
        Try(i, j+1, s);
        a[i][j+1]=1;
        s.pop_back();
    }
    if(i-1>=0 && a[i-1][j]==1){
        s+="U";
        a[i-1][j]=0;
        Try(i-1, j, s);
        a[i-1][j]=1;
        s.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    a[1][1]=0;
    Try(1, 1, ""); 
    if(!check) cout << "-1";
}