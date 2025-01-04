#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; 
    cin >> T;

    while (T--) {
        int n; 
        cin >> n;

        vector<int> a(n + 1);
        vector<int> dp(n + 1, 1); 

        for (int i = 1; i <= n; i++) cin >> a[i];

        int max_len = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if (a[i] > a[j] && (a[i] + a[j]) % 2 != 0) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            max_len = max(max_len, dp[i]);
        }

        cout << max_len << "\n";
    }

    return 0;
}
