// Dem so cap (i, j) sao cho a[k] = a[i] + a[j] voi i < j < k

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    
    sort(a.begin(), a.end()); 

    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int p = a[i] + a[j];
            if(binary_search(a.begin(), a.end(), p)){
                cnt++;
            }
        }
    }
    cout << cnt % MOD;
}