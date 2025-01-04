#include <bits/stdc++.h>
using namespace std;

// Ngan hang can chia n tui tien co gia tri khac nhau thanh 2 nhom (dai dien cho 2 xe van chuyen) sao cho su chenh lech tong gia tri giua 2 nhom la nho nhat.
int main(){
    int n;
    cin >> n;
    int a[25];
    int sum = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }

    int each = sum/2;
    vector<int> dp(sum+5, 0);
    dp[0] = 1;

    for (int i = 0; i < n; i++){
        for (int j = sum; j >= a[i]; j--){
            if (dp[ j - a[i] ] == 1) dp[j] = 1;
        }
    }

    int each_l, each_r;
    for (int i = each; i >= 0; i--){
        if (dp[i]){
            each_l = i;
            break;
        }
    }
    for (int i = each + 1; i <= sum; i++){
        if (dp[i]){
            each_r = i;
            break;
        }
    }

    if ((each_l - each) < (each_r - each)){
        each = each_l;
    } else {
        each = each_r;
    }

    cout << abs((sum-each) - each);
}
