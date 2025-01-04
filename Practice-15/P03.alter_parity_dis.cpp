#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;  
        vector<int> A(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i];  
        }

        vector<int> dp(n, 1); 

        for (int i = 1; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (A[i] < A[j] && (A[i] + A[j]) % 2 != 0) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        cout << *max_element(dp.begin(), dp.end()) << endl;
    }
}

int main() {
    solve();
    return 0;
}
