#include<bits/stdc++.h>
using namespace std;

int n, M;
int a[10005];// day he so
int x[10005];// day nghiem
int t[10005];// tong tien to
int f = 0;
int res =0;

void Try( int k){
    for( int v = 1; v <= ( M - f -(t[n]-t[k]) )/a[k] ; v++){
        x[k] = v;
        f += x[k] * a[k];

        if( k == n ){
           if( f == M ) res+=1;
        }
        else{
            Try( k+1 );
        }

        f -= x[k] * a[k];
    }
}

int main(){
    // #define NAME "equation."
    // freopen(NAME"inp","r",stdin);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>> n >> M;
    // int a[n]; khong viet nhu nay
    for(int i = 1; i<= n;i++){
        cin>> a[i];
        t[i]= t[i-1] +a[i];
    }
    Try(1);
    cout << res;
    return 0;
}
