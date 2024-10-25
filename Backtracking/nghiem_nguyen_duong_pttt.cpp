#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, M;
int x[100];
int T; // accumulated sum

int check(int v, int k){
    if(k < n) return 1;
    return T + v == M;
}

void sol(){
    for(int i=1; i<=n; i++){
        cout << x[i];
    }
    cout << "\n";
}

void Try(int k){
    for(int v=1; v<= M-T - n+k; v++){
        if(check(v,k)){
            X[k] = v;
            
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

}