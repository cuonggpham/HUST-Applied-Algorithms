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

    sort(a.begin(), a.end());  
    int res = 0;

    for (int i = 0; i < n - 2; i++) {
        int p1 = i + 1, p2 = n - 1; 
        while (p1 < p2) {  
            if (a[i] + a[p1] + a[p2] == k) {  
                res = 1;
                break; 
            } else if (a[i] + a[p1] + a[p2] < k) {  
                p1++;
            } else {  
                p2--;
            }
        }
        if (res) break;
    }

    if (res) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
