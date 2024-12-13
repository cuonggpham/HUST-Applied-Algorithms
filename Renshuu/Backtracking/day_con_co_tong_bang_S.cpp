#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int X[100], a[100], n, k;

void input(){
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1);
}

void Try(int i, int pos, int sum){
    for(int j=pos; j<=n; j++){
        X[i] = a[j];
        sum += a[j];
        if(sum == k){
            for(int l=1; l<=i; l++){
                cout << X[l] << " ";
            }
            cout << endl;
        } 
        else if(sum < k){
            Try(i+1, j+1, sum);
        }
        sum -= a[j];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    Try(1, 1, 0);
}