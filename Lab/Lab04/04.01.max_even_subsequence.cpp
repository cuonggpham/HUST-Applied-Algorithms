#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007

int n;
ll a[100000005];
ll S0 = -1e9+1;
ll S1 = -1e9+1;
ll res = S0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];

    if(a[0] % 2 == 0){
        S0 = a[0];
    }
    else {
        S1 = a[0];
    } 

    for(int i=1; i<n; i++) {
        if(a[i] % 2 == 0){
            S0 = max(S0 + a[i], a[i]);
            if (S1 != -1e9+1) {
                S1 += a[i];
            }
        }
        else {
            ll new_S1 = max(S0 + a[i], a[i]);
            S0 = S1 + a[i];
            S1 = new_S1;
        }
        res = max(res, S0);
    }

    if (res == -1e9+1) {
        cout << "NOT_FOUND\n";
    } else {
        cout << res << '\n';
    }     
}
