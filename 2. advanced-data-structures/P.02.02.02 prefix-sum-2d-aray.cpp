// prefix[i][j]=a[i][j]+prefix[i−1][j]+prefix[i][j−1]−prefix[i−1][j−1]
// sum=prefix[r2][c2]−prefix[r1−1][c2]−prefix[r2][c1−1]+prefix[r1−1][c1−1]

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6+5;
int n, m;

void input(){
    cin >> n >> m;
    int a[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
        }
    }
}

void solve(){
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


}