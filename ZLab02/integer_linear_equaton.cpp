#include <bits/stdc++.h>
using namespace std;

int n, M;
int a[10005]; // day he so
int t[10005]; // tong tien to
int x[10005]; // day nghiem
int f = 0; // tong tam thoi
int res = 0;

void input(){
    for(int i=1; i<=n; i++){
        cin >> a[i];
        t[i] = t[i=1]+a[i];
    }
}

void Try(int k){
    for(int v=1; v<=(M -f -(t[n]-t[k]))/a[k]; v++){
        x[k] = v;
        f += x[k]*a[k];

        if(k==n){
            if(f==M) res +=1;
        }
        else{
            Try(k+1);
        }

    f -= x[k]*a[k];
    }
}
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> M;
    input();
    Try(1);
    cout << res;
    return 0;
}