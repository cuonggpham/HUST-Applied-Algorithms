#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 1;
int a[N][N]; // Ma trận lưu các giá trị đầu vào
int n, m;    // Số hàng và số cột của ma trận
long long h[N]; // Mảng lưu chiều cao của các cột khi xây dựng histogram
long long L[N], R[N]; // Mảng lưu vị trí cận trái và phải cho mỗi cột
vector<long long> V;  // Vector hỗ trợ tính toán cận trái và phải

// Hàm nhập dữ liệu
void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
}

// Hàm tính diện tích lớn nhất của hình chữ nhật trong histogram hiện tại
long long compute() {
    h[0] = -1;       // Thiết lập biên trái ngoài cùng
    h[m + 1] = -1;   // Thiết lập biên phải ngoài cùng
    V.clear();       // Xóa vector lưu trữ các cột trước đó

    // Tính mảng R (cận phải cho mỗi cột)
    for (int i = 1; i <= m + 1; i++) {
        while (!V.empty() && h[i] < h[V.back()]) {
            R[V.back()] = i;
            V.pop_back();
        }
        V.push_back(i);
    }

    V.clear(); // Xóa vector để tái sử dụng cho việc tính mảng L

    // Tính mảng L (cận trái cho mỗi cột)
    for (int i = m; i >= 0; i--) {
        while (!V.empty() && h[i] < h[V.back()]) {
            L[V.back()] = i;
            V.pop_back();
        }
        V.push_back(i);
    }

    // Tính diện tích lớn nhất của hình chữ nhật có thể tạo ra từ histogram
    unsigned long long maxArea = 0;
    for (int i = 1; i <= m; i++) {
        unsigned long long area = (R[i] - L[i] - 1) * h[i];
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

// Hàm giải quyết bài toán tìm diện tích lớn nhất của hình chữ nhật trong ma trận
void solve() {
    long long maxRectangle = 0;

    // Khởi tạo mảng chiều cao h với giá trị ban đầu là 0
    for (int i = 1; i <= m; i++) {
        h[i] = 0;
    }

    // Duyệt qua từng hàng của ma trận
    for (int i = 1; i <= n; i++) {
        // Cập nhật chiều cao cho histogram
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 0) {
                h[j] = 0;
            } else {
                h[j] += 1;
            }
        }

        // Tính diện tích lớn nhất của hình chữ nhật từ histogram hiện tại
        long long currentMax = compute();
        maxRectangle = max(maxRectangle, currentMax);
    }

    // In ra kết quả diện tích lớn nhất
    cout << maxRectangle;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    solve();
    return 0;
}
