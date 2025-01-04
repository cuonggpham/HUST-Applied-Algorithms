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
    int min_gift = 1e9+5;

    for(int p2=0; p2<n; p2++){
        sum += a[p2];
        while(sum >= s){
            min_gift = min(min_gift, p2-p1+1);
            sum -= a[p1];
            p1++;
        }
        
    }
    if(min_gift == 1e9+5){
        cout << "-1";
    } else {
        cout << min_gift;
    }
}