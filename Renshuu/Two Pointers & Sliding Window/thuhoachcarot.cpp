#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6+5;
int n, m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> S(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            S[i][j] = a[i][j] + S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1];
        }
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int r1, c1, r2, c2;
        cin >> r1 >> r2 >> c1 >> c2;

        int res = S[r2][c2];
        if (r1 > 1) res -= S[r1 - 1][c2];
        if (c1 > 1) res -= S[r2][c1 - 1];
        if (r1 > 1 && c1 > 1) res += S[r1 - 1][c1 - 1];

        cout << res << "\n";
    }
    return 0;
}