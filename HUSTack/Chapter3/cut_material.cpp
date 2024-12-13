#include <iostream>
#include <vector>
using namespace std;

int H, W, n;
vector<pair<int, int>> rects;
vector<vector<bool>> used;

// Kiểm tra xem có thể đặt hình chữ nhật vào vị trí (x, y)
bool canPlace(int x, int y, int h, int w) {
    if (x + h > H || y + w > W) return false; // Vượt ra ngoài giới hạn
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (used[x + i][y + j]) return false; // Đã bị sử dụng
        }
    }
    return true;
}

// Đánh dấu vùng đã sử dụng hoặc xóa đánh dấu
void place(int x, int y, int h, int w, bool status) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            used[x + i][y + j] = status;
        }
    }
}

// Hàm đệ quy để xếp các hình chữ nhật
bool backtrack(int idx) {
    if (idx == n) return true; // Đã xếp hết các hình
    int h = rects[idx].first, w = rects[idx].second;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            // Thử đặt hình chữ nhật theo chiều gốc
            if (canPlace(i, j, h, w)) {
                place(i, j, h, w, true);
                if (backtrack(idx + 1)) return true;
                place(i, j, h, w, false);
            }
            // Thử đặt hình chữ nhật sau khi xoay 90 độ
            if (canPlace(i, j, w, h)) {
                place(i, j, w, h, true);
                if (backtrack(idx + 1)) return true;
                place(i, j, w, h, false);
            }
        }
    }
    return false;
}

int main() {
    cin >> H >> W >> n;
    rects.resize(n);
    used.assign(H, vector<bool>(W, false));

    for (int i = 0; i < n; i++) {
        cin >> rects[i].first >> rects[i].second;
    }

    if (backtrack(0)) cout << 1 << endl;
    else cout << 0 << endl;

    return 0;
}
