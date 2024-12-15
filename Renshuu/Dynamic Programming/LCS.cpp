// Cho 2 xau ki tu S va T, hay tim xau con chung dai nhat cua S va T. Cac ki tu cua xau con khong nhat thiet phai lien ke nhau.
// Input Format
// Dong dau tien la xau S; Dong thu 2 la xau T;
// Constraints
// S va T chi gom cac chu cai in hoa va co do dai khong qua 1000
// Output Format
// In ra do dai xau con chung dai nhat cua S va T
// Sample Input 0
// ZHFTDFHF
// TFISHROV
// Sample Output 0
// 3 

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);cout.tie(NULL);

    string S, T;
    cin >> S >> T;
    int n = S.length(), m = T.length(); 
    int dp[1001][1001] = {0};

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (S[i - 1] == T[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[n][m] << "\n";
    return 0;
}
