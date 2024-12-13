#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n, Q;

    cin >> n;
    vector<int> a(n+1, 0);
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }

    vector<int> S(n+1, 0);
    for(int i=1; i<=n; i++){
        S[i]= S[i-1]+a[i];
    }

    cin >> Q;
    while(Q--){
        int i, j;
        cin >> i >> j;
        cout << S[j] - S[i-1] << endl;
    }
}

// 5
// 5 8 7 1 9 
// 4
// 1 2
// 1 5
// 1 3
// 4 5

// Output 
// 13
// 30
// 20
// 10 