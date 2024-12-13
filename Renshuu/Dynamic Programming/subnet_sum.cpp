#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    vector<bool> dp(S+1, false);
    dp[0] = true;
    for(int i=0; i<n; i++){
        for(int j=s; j>=a[i]; j--){
            if(dp[j - a[i]] == true){
                dp[j] = true;
            }
        }
    }
    if(dp[s]) cout << 1 << "\n";
    else cout << 0 << "\n";
}