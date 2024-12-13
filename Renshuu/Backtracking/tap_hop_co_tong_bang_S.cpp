#include <bits/stdc++.h>
using namespace std;

int n, k, s; // n: so phan tu toi da, k: so phan tu can chon, s: tong can dat
int cnt = 0; // Bien dem so tap hop thoa man dieu kien

// Ham de quy Try de tim tat ca cac tap hop thoa man dieu kien
void Try(int i, int pos, int sum) {
    // i: so luong phan tu da chon
    // pos: chi so hien tai trong tap hop
    // sum: tong hien tai cua cac phan tu da chon
    // Neu da chon du k phan tu va tong dung bang s, tang bien dem
    if (i == k && sum == s) {
        cnt++;
        return;
    }
    // Neu so phan tu da chon vuot k hoac tong vuot s, ket thuc nhanh nay
    if (i >= k || sum >= s) return;
    // Thu chon cac phan tu tu pos den n
    for (int j = pos; j <= n; j++) {
        Try(i + 1, j + 1, sum + j);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k >> s;   
    Try(0, 1, 0); // Bat dau de quy tu trang thai ban dau: chua chon phan tu nao, tong la 0
    cout << cnt << endl; // In ra ket qua la so luong tap hop thoa man
    return 0;
}
