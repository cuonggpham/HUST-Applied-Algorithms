#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n, Q;

    cin >> n >> Q;
    vector<int> a(n+1, 0);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    vector<int> S(n+1, 0);
    for(int i=0; i<n; i++){
        S[i]= S[i-1]+a[i];
    }

    while(Q--){
        int i, j;
        cin >> i >> j;
        cout << S[j] - S[i-1] << endl;
    }
}