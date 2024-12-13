#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, Q;
    cin >> N >> Q;
    
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // Mảng để lưu các sự thay đổi
    vector<int> diff(N + 1, 0);

    // Xử lý các thao tác
    for (int i = 0; i < Q; i++) {
        int L, R, K;
        cin >> L >> R >> K;
        
        // Cập nhật mảng diff
        diff[L] += K;
        if (R + 1 < N) {
            diff[R + 1] -= K;
        }
    }

    // Áp dụng mảng diff vào mảng A
    int add = 0;  // Biến để lưu tổng các sự thay đổi
    for (int i = 0; i < N; i++) {
        add += diff[i];  // Tính tổng dồn
        A[i] += add;     // Cập nhật giá trị thực tế cho mảng A
    }

    for (int i = 0; i < N; i++) {
        cout << diff[i] << " ";
    }
    cout << endl;
    
    // In kết quả
    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
