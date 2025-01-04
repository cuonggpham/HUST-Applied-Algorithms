// Tim do dai dai nhat cua day con lien tiep co tinh chat chan le xen ke

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
        if((a[i] - a[i-1]) % 2 != 0){
            curr_len++;
        } else {
            curr_len = 1;
        }
        max_len = max(max_len, curr_len);
    }

    cout << max_len << endl;
}