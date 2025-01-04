#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e9 + 7;

int n, Q, d;
int a[30][30];
int visited[30];
int pick[30];
int rt[30];
int f = 0;
int load = 0;
int f_best = INF;
int dmin = INF;
int xp[30];  // vi tri don khach
int dt[30]; // vi tri tra khach
int dst_on_bus[30];
int on_bus[30];

// debug
// void disp() {
//     for (int i = 1; i <= 2 * n; i++) {
//         cout << rt[i] << " ";
//     }
//     cout << ", f_best = " << f + a[rt[2 * n]][0] << '\n';
//     for (int i = 1; i <= n; i++) {
//         cout << "Customer " << i << " on " << xp[i] << " off " << dt[i] << '\n';
//     }
//     cout << '\n';
// }

bool check(int i) {
    if (visited[i]) return false;
    if (i <= n) return true;
    return pick[i - n];
}

void Try(int k) {
    for (int i = 1; i <= 2 * n; i++) {
        if (check(i)) {
            rt[k] = i;
            visited[i] = 1;

            for (int p = 1; p <= n; p++) {
                if (on_bus[p]) {
                    dst_on_bus[p] += a[rt[k - 1]][rt[k]];
                }
            }

            if (i <= n) {
                pick[i] = 1;
                xp[i] = k;
                load++;
                on_bus[i] = 1;
            } else {
                dt[i - n] = k;
                load--;
                on_bus[i - n] = 0;
            }

            f += a[rt[k - 1]][rt[k]];

            bool is_valid = (load <= Q) && (f+ dmin * (2 * n - k + 1) < f_best);
            if (is_valid) {
                for (int p = 1; p <= n; p++) {
                    if (dst_on_bus[p] > d) {
                        is_valid = false;
                        break;
                    }
                }
            }

            if (k == 2 * n) {
                f_best = min(f_best, f + a[rt[2 * n]][0]);
            } else if (is_valid) {
                Try(k + 1);
            }
            visited[i] = 0;
            f -= a[rt[k - 1]][rt[k]];

            if (i <= n) {
                pick[i] = 0;
                load--;
                on_bus[i] = 0;
            } else {
                load++;
                on_bus[i - n] = 1;
            }

            for (int p = 1; p <= n; p++) {
                if (on_bus[p]) {
                    dst_on_bus[p] -= a[rt[k - 1]][rt[k]];
                }
            }
        }
    }
}

void solve() {
    cin >> n >> Q >> d;
    for (int i = 0; i <= 2 * n; i++) {
        for (int j = 0; j <= 2 * n; j++) {
            cin >> a[i][j];
            if(i!=j) dmin = min(dmin, a[i][j]);
        }
    }

    memset(visited, 0, sizeof(visited));
    memset(pick, 0, sizeof(pick));
    memset(rt, 0, sizeof(rt));
    memset(on_bus, 0, sizeof(on_bus));
    memset(dst_on_bus, 0, sizeof(dst_on_bus));

    Try(1);

    if (f_best == INF) {
        cout << -1 << '\n';
    } else {
        cout << f_best << '\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}
