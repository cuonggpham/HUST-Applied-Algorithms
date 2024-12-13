#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000000; // Số phần tử tối đa trong mảng
const int LOG = 30;        // Số lượng bit để biểu diễn giá trị tối đa của log2(n)

int n;
int A[MAX_N];
int M[LOG][MAX_N]; // Mảng lưu giá trị chỉ số của các phần tử nhỏ nhất trong các đoạn

// Hàm tiền xử lý mảng A để xây dựng bảng RMQ (Range Minimum Query)
void preprocessing() {
    // Khởi tạo các giá trị của M với -1
    for (int j = 0; (1 << j) <= n; j++) {
        for (int i = 0; i < n; i++) {
            M[j][i] = -1;
        }
    }

    // Gán giá trị ban đầu cho M[0][i] là i, tương ứng với chỉ số của chính nó
    for (int i = 0; i < n; i++) {
        M[0][i] = i;
    }

    // Xây dựng bảng RMQ
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) - 1 < n; i++) {
            // Kiểm tra phần tử nhỏ nhất giữa hai đoạn con
            if (A[M[j - 1][i]] < A[M[j - 1][i + (1 << (j - 1))]]) {
                M[j][i] = M[j - 1][i];
            } else {
                M[j][i] = M[j - 1][i + (1 << (j - 1))];
            }
        }
    }
}

// Hàm trả về chỉ số của phần tử nhỏ nhất trong đoạn [i, j] của mảng A
int rmq(int i, int j) {
    int k = log2(j - i + 1);
    int p2k = (1 << k); // 2^k

    // Trả về chỉ số của phần tử nhỏ nhất giữa hai đoạn con
    if (A[M[k][i]] <= A[M[k][j - p2k + 1]]) {
        return M[k][i];
    } else {
        return M[k][j - p2k + 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Nhập vào số phần tử của mảng
    cin >> n;

    // Nhập giá trị cho mảng A
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // Tiền xử lý bảng RMQ
    preprocessing();

    int ans = 0, m;

    // Nhập vào số lượng truy vấn
    cin >> m;
    for (int i = 0; i < m; i++) {
        int I, J;
        cin >> I >> J;
        ans += A[rmq(I, J)];
    }

    // In ra kết quả
    cout << ans << endl;

    return 0;
}
