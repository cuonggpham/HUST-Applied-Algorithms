// tim thanh phan lien thong lon nhat
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001; 
vector<int> adj[MAXN]; 
bool visited[MAXN];   

void inp(int &n, int &m) {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a); // Đồ thị vô hướng
    }
}

int dfs(int u) {
    visited[u] = true;
    int count = 1; // Bắt đầu với đỉnh hiện tại
    for (int v : adj[u]) {
        if (!visited[v]) {
            count += dfs(v); // Đệ quy để duyệt đỉnh kề
        }
    }
    return count;
}

int main() {
    int n, m;
    inp(n, m);

    int max_group_size = 0; // Kích thước lớn nhất của nhóm
    memset(visited, false, sizeof(visited)); // Đặt toàn bộ visited = false
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) { // Nếu đỉnh chưa được thăm
            max_group_size = max(max_group_size, dfs(i));
        }
    }

    cout << max_group_size << endl; 
    return 0;
}
