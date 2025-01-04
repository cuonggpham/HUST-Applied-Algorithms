// Tim so bo ba phan tu trong mang co tong bang Q
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

    int n, Q; cin >> n >> Q;
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];
    
    sort(a, a + n); 

    int cnt=0;
    for(int i=0; i<n-2; i++){
        int p1=i+1, p2=n-1;
        while(p1 < p2){
            if((a[i] + a[p1] + a[p2]) == Q){
                cnt++;
                p1++; 
                p2--;
            }
            else if((a[i] + a[p1] + a[p2]) < Q){
                p1++;
            }
            else{
                p2--;
            }
        }
    }
    cout << cnt % MOD;
}