#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, s;
    cin >> n >> s;  
    int a[n];
    for(int i=0; i<n; i++)  cin >> a[i];
    
    int p1=0;
    ll sum = 0;
    int max_gift = 0;

    for(int p2=0; p2<n; p2++){
        sum += a[p2];
        while(sum > s){
            sum -= a[p1];
            p1++;
        }
        max_gift = max(max_gift, p2-p1+1);
    }
    cout << max_gift;
}