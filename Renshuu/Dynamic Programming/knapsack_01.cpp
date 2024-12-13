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

    int n, S; cin >> n >> S;
    int w[n+1], v[n+1];
    for(int i=1; i<=n; i++) cin >> w[i];
    for(int i=1; i<=n; i++) cin >> v[i];
    int dp[n+1][S+1];
    memset(dp, 0, sizeof(dp));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=S; j++){
            // Khong lua chon do vat thu i vao trong tui
            dp[i][j] = dp[i-1][j];
            // Co the dua do vat vao trong tui
            if(j >= w[i]) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]] + v[i]);
            }
        }
    }
    // In xem thu bang lua chon
    for(int i=1; i<=n; i++){
        for(int j=1; j <= S; j++){
            cout << dp[i][j] << ' ';
        }
        cout << "\n";
    }
    // Result
    cout << dp[n][S] << "\n";
}