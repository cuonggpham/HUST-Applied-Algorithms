#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, m; 
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int j = 0; j < m; j++) cin >> b[j];

    vector<int> result;
    ll i = 0, j = 0;
    // Merging two sorted arrays in linear time
    while(i < n && j < m){
        if(a[i] < b[j]){
            result.push_back(a[i]);
            i++;
        } else {
            result.push_back(b[j]);
            j++;
        }
    }
    while(i < n){
        result.push_back(a[i]);
        i++;
    }
    while(j < m){
        result.push_back(b[j]);
        j++;
    }

    for(int num : result){
        cout << num << " ";
    }
}