#include<bits/stdc++.h>
using namespace std;
int n, m;
vector< int > kh[50]; // nhung giao vien co the day khoa hoc i
vector< int > gv[50]; // nhung khoa hoc giao vien i dang day
int a[50][50];
int load[50];

int res = 1000 ;
bool check( int g, int k){
    for( int i : gv[g] ){
        if( a[i][k] == 1 ) return false;
    }
    return true;
}

void Try( int k){
    for( int g : kh[ k ] ){
        if( check( g , k ) ){
            load[g] ++;
            gv[g]. push_back( k );

            if( k < n){
                if( load[g] < res) Try(k+1);
            }
            else{
                int loadres = -1 ;
                for( int i =1 ; i <= m; i++ ){
                    loadres= max( loadres, load[ i ]);
                }
                res= min( res, loadres );
            }

            load[g] --;
            gv[g].pop_back();
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> m >> n;
    for( int i = 1; i <= m; i++){
        int k;
        cin >> k;
        for( int j = 1; j <= k ;j++){
            int u; cin>> u;
            kh[u].push_back(i);
        }
    }
    int k; cin>> k;
    for( int i = 1; i <= k ;i++){
        int u,v; cin>> u>> v;
        a[u][v] = a[v][u] = 1;
    }
    Try(1);
    if( res != 1000)
        cout << res;
    else
        cout<< "-1";
    return 0;
}