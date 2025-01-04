#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m; cin >> n >> m;
    int a[n], b[m];
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<m; i++) cin >> b[i];
    int i=0, j=0;
    while(i < n && j<m){
        if(b[j] > a[i]){
            i++;
        }
        else {
            cout << i << " ";
            j++;
        }
    }
    while(j<m){
        cout << n << " ";
        j++;
    }
}