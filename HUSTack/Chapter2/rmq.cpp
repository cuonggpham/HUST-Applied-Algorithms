#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007

const int N = 1e6 + 5;
int n, m;
int a[N];
int M[N][20]; // Sparse table

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;
}

void preprocessing() {
    for (int i = 0; i < n; i++) {
        M[i][0] = i; 
    }

    // Build the Sparse Table
    for (int j = 1; (1 << j) <= n; j++) { // Iterate over all power levels
        for (int i = 0; i + (1 << j) - 1 < n; i++) { // Iterate over valid ranges
            if (a[M[i][j - 1]] < a[M[i + (1 << (j - 1))][j - 1]]) {
                M[i][j] = M[i][j - 1]; // Store the index of the minimum element
            } else {
                M[i][j] = M[i + (1 << (j - 1))][j - 1];
            }
        }
    }
}

int RMQ(int l, int r) {
    int len = r - l + 1;
    int j = log2(len); // Find the largest power of 2 that fits within the range
    // Compare the two overlapping intervals
    if (a[M[l][j]] < a[M[r - (1 << j) + 1][j]]) {
        return a[M[l][j]];
    } else {
        return a[M[r - (1 << j) + 1][j]];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    preprocessing();

    ll res = 0; // Use long long to handle large sums
    while (m--) {
        int l, r;
        cin >> l >> r;
        res += RMQ(l, r);
    }

    cout << res << endl;

    return 0;
}
