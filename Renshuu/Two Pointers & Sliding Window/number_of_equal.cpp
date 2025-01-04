#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m; 
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    int i = 0, j = 0;
    ll cnt = 0;

    while(i < n && j < m){
        if(a[i] < b[j]){
            ++i;
        }
        else if (a[i] > b[j]){
            ++j;
        }
        else {
            int cnt1 = 0, cnt2 = 0;
            int tmp = a[i];
            while(i < n && a[i] == tmp){
                cnt1++; 
                i++;
            }
            while(j < m && b[j] == tmp) {
                cnt2++; 
                j++;
            }
            cnt += 1ll * cnt1 * cnt2;
        }
    }
    cout << cnt << "\n";
}