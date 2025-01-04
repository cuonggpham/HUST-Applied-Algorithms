#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);  
    for (int i = 0; i < n; i++) {
        cin >> a[i];  
    }
    
    for (int i = 0; i <= n - k; i++) {
        int max1 = -1e9+1;
        int min1 = 1e9+1;
        for (int j = i; j < i + k; j++) {
            max1 = max(max1, a[j]);
            min1 = min(min1, a[j]);
        }
        cout << min1 << " " << max1 << "\n";
    }

    return 0;
}
