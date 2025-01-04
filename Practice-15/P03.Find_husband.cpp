// Chon mot tap con cua mot tap hop so nguyen sao cho:
// Tong cua cac so trong tap con khong vuot qua M.
// Hieu giua M va tong cua tap con la nho nhat.
// Chi tiet yeu cau:
// Dau vao:
// So nguyen n: So luong so nguyen (tu 1 den 20).
// Mot danh sach n so nguyen, gia tri cua moi so nam trong khoang tu 1 den 1000.
// So nguyen M: Gia tri gioi han (tu 1 den 100000).
// Dau ra:
// Mot so tu nhien: Hieu nho nhat giua M va tong cua cac so trong tap con duoc chon.

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int a[104];
    int sum = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }

    sort(a, a+n);

    int m; cin >> m;
    vector<int> dp(sum+5, 0);

    dp[0] = 1;

    for (int i = 0; i < n; i++){
        for (int j = sum; j >= a[i]; j--){
            if (dp[ j - a[i] ] == 1){
                dp[j] = 1;
            }
        }
    }

    for (int j = m; j >= 0; j--){
        if (dp[j]){
            cout << m - j;
            return 0;
        }
    }
}
