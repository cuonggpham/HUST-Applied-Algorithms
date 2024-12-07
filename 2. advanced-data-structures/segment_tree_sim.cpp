#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005; 
int n, m;               
int a[maxn];            
int t[maxn * 4];        

void build(int v, int l, int r) {
    if (l == r) {
        t[v] = a[l]; // Leaf node
    } else {
        int m = (l + r) / 2;
        build(2 * v, l, m);
        build(2 * v + 1, m + 1, r);
        t[v] = max(t[2 * v], t[2 * v + 1]); // Store maximum
    }
}

void update(int v, int l, int r, int pos, int val) {
    if (l == r) {
        t[v] = val; // Update leaf node
    } else {
        int m = (l + r) / 2;
        if (pos <= m) {
            update(2 * v, l, m, pos, val);
        } else {
            update(2 * v + 1, m + 1, r, pos, val);
        }
        t[v] = max(t[2 * v], t[2 * v + 1]); // Update parent node
    }
}

int get_max(int v, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) {
        return INT_MIN; // Out of range
    }
    if (ql <= l && r <= qr) {
        return t[v]; // Fully inside range
    }
    int m = (l + r) / 2;
    return max(get_max(2 * v, l, m, ql, qr), get_max(2 * v + 1, m + 1, r, ql, qr));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    build(1, 0, n - 1);
    cin >> m;

    for (int i = 0; i < m; i++) {
        string op;
        cin >> op;
        if (op == "update") {
            int idx, val;
            cin >> idx >> val;
            update(1, 0, n - 1, idx - 1, val); 
        } else if (op == "get-max") {
            int l, r;
            cin >> l >> r;
            cout << get_max(1, 0, n - 1, l - 1, r - 1) << '\n'; 
        }
    }
    return 0;
}
