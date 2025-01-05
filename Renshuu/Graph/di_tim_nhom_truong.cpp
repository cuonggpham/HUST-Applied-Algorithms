#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001; // Số lượng sinh viên tối đa
vector<int> adj[MAXN]; // Danh sách kề
bool visited[MAXN];    // Mảng đánh dấu các đỉnh đã thăm
int group_leader;      // Trưởng nhóm của nhóm hiện tại
int max_degree;        // Số mối quan hệ lớn nhất trong nhóm

// Hàm nhập dữ liệu
void inp(int &n, int &m) {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a); // Đồ thị vô hướng
    }
}

// Hàm DFS để tìm trưởng nhóm trong một thành phần liên thông
void dfs(int u) {
    visited[u] = true;
    int degree = adj[u].size(); // Số lượng mối quan hệ của đỉnh u

    // Cập nhật trưởng nhóm nếu u có số mối quan hệ lớn hơn
    // hoặc nếu số mối quan hệ bằng nhau nhưng u có số thứ tự nhỏ hơn
    if (degree > max_degree || (degree == max_degree && u < group_leader)) {
        max_degree = degree;
        group_leader = u;
    }

    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v); // Đệ quy để duyệt toàn bộ thành phần liên thông
        }
    }
}

int main() {
    int n, m;
    inp(n, m);

    vector<int> leaders; // Danh sách các trưởng nhóm
    memset(visited, false, sizeof(visited)); // Đặt toàn bộ visited = false

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) { // Nếu đỉnh chưa được thăm
            group_leader = i;  // Mặc định trưởng nhóm ban đầu là i
            max_degree = adj[i].size(); // Ban đầu số mối quan hệ của i
            dfs(i); // Tìm trưởng nhóm của nhóm liên thông
            leaders.push_back(group_leader); // Thêm trưởng nhóm vào danh sách
        }
    }

    sort(leaders.begin(), leaders.end());

    for (int leader : leaders) {
        cout << leader << " ";
    }
    cout << endl;

    return 0;
}
