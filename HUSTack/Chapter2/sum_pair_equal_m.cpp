#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n, Q;
    cin >> n >> Q;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }   
    sort(a.begin(), a.end());    
    int l = 0, r = n - 1;
    int count = 0;
    
    while (l < r) {
        int sum = a[l] + a[r];
        if (sum == Q) {
            count++;
            l++;
            r--;
        } else if (sum < Q) {
            l++;  
        } else {
            r--; 
        }
    }
    
    cout << count << endl;

    return 0;
}