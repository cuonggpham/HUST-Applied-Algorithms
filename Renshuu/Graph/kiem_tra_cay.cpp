#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;
vector<int> adj[MAXN]; 
bool visited[MAXN];   

// Hàm DFS kiểm tra liên thông và phát hiện chu trình
bool dfs(int u, int parent) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            if (!dfs(v, u)) return false; // Nếu phát hiện chu trình, trả về false
        } else if (v != parent) {
            return false; // Chu trình phát hiện khi đỉnh kề đã thăm và không phải cha của đỉnh hiện tại
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    if (m != n - 1) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(visited, false, sizeof(visited));
    if (!dfs(1, -1)) {
        cout << 0 << endl; 
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cout << 0 << endl; // Nếu có đỉnh không được thăm, không liên thông
            return 0;
        }
    }

    cout << 1 << endl;
    return 0;
}
