// Tim day con tang dan co so phan tu lon nhat trong day a
// Input: so nguyen duong n va day a gom n phan tu
// Output: so phan tu cua day con tang dan dai nhat

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
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];

    int max_len = 1, curr_len = 1;
    for(int i=1; i<n; i++){
        if(a[i] > a[i-1]){
            curr_len++;
        } else {
            curr_len = 1;
        }
        max_len = max(max_len, curr_len);
    }

    cout << max_len << endl;
}