#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;
int n;
int board[MAXN][MAXN]; 
bool visited[MAXN][MAXN]; 
int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1}; 

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n && board[x][y] == 1 && !visited[x][y];
}

int bfs(int sx, int sy, int ex, int ey) {
    queue<pair<pair<int, int>, int>> q; 
    q.push({{sx, sy}, 0});
    visited[sx][sy] = true;

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        int x = curr.first.first;
        int y = curr.first.second;
        int steps = curr.second;

        if (x == ex && y == ey) {
            return steps;
        }

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isValid(nx, ny)) {
                visited[nx][ny] = true;
                q.push({{nx, ny}, steps + 1});
            }
        }
    }

    return -1;
}

int main() {
    cin >> n;
    int s, t, u, v;
    cin >> s >> t >> u >> v;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    memset(visited, false, sizeof(visited));
    int result = bfs(s - 1, t - 1, u - 1, v - 1);

    cout << result << endl;
    return 0;
}
