#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

const int MAX_N = 1000; // Kích thước tối đa của mảng
const int INF = 1e9 + 7;

// Khai báo mảng lưu trữ dữ liệu và các biến cần thiết
int grid[MAX_N][MAX_N], dist[MAX_N][MAX_N];
int m, n, startRow, startCol;
int dx[] = {1, 0, -1, 0}; // Di chuyển theo hàng: xuống, sang phải, lên, sang trái
int dy[] = {0, 1, 0, -1}; // Di chuyển theo cột: xuống, sang phải, lên, sang trái

queue<ii> q; // Hàng đợi dùng để thực hiện BFS

int solve() {
    // Đẩy vị trí bắt đầu vào hàng đợi và khởi tạo giá trị khoảng cách
    q.push({startRow, startCol});
    dist[startRow][startCol] = 0;
    grid[startRow][startCol] = 1; // Đánh dấu ô đã được thăm

    // BFS để tìm đường thoát
    while (!q.empty()) {
        ii current = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int newX = current.first + dx[i];
            int newY = current.second + dy[i];

            // Kiểm tra nếu vị trí mới vượt ra khỏi biên thì trả về khoảng cách
            if (newX < 1 || newX > m || newY < 1 || newY > n) {
                return dist[current.first][current.second] + 1;
            }

            // Nếu ô chưa được thăm và không phải là vật cản
            if (grid[newX][newY] != 1) {
                dist[newX][newY] = dist[current.first][current.second] + 1;
                q.push({newX, newY});
                grid[newX][newY] = 1; // Đánh dấu ô đã được thăm
            }
        }
    }

    // Nếu không tìm thấy đường thoát, trả về -1
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // Nhập kích thước của lưới và vị trí bắt đầu
    cin >> m >> n >> startRow >> startCol;

    // Nhập dữ liệu lưới
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }

    // Gọi hàm giải và in kết quả
    int result = solve();
    cout << result;

    return 0;
}
