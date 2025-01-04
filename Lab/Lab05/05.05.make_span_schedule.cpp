// Du an co n cong viec 1, ..., n. Cong viec i co thoi gian hoan thanh la d(i) (i=1, ..., n). 
// Co cac rang buoc truoc giua cac cong viec duoc bieu dien boi tap Q cac cap: voi moi (i,j) trong Q, 
// cong viec j khong the bat dau truoc khi cong viec i hoan thanh. Tinh thoi gian hoan thanh som nhat cua du an.
// Dau vao
// Dong 1: chua n va m (1 <= n <= 10^4, 1 <= m <= 200000)
// Dong 2: chua d(1), ..., d(n) (1 <= d(i) <= 1000)
// Dong i+3 (i=1, ..., m): chua i va j: cong viec j khong the bat dau truoc khi cong viec i hoan thanh
// Dau ra
// Ghi ra thoi gian hoan thanh som nhat cua du an

#include<bits/stdc++.h>

using namespace std;
int n, m;
int edg[10005][10005];
int deg[10005] ={};
int d[10005] ={};
int a[10005] ={};
int F[10005] ={};
int main(){
    cin>> n>> m;
    for( int i =1 ;i<= n ; i++){
        cin>> d[i];
    }
    for( int i = 1 ; i<= m ;i++){
        int u,v;
        cin>> u>> v;
        edg[u][v] = 1;
        deg[v]++;
    }
    //TOPO
    queue<int> q;
    for( int i = 1 ;i<= n ;i++){
        if( deg[i] == 0) q.push(i);
    }
    int i=0;
    while( !q.empty()){
        int u= q.front(); q.pop();
        i++;
        a[i] = u;
        for( int v= 1 ; v<= n ; v++ ){
            if( edg[u][v] == 1){
                deg[v]--;
                if( deg[v] == 0)q.push(v);
            }
        }
    }
    // makespan
    int res = -1e9;
    for( int i =1 ; i<= n ;i ++){
        F[i]+= d[a[i]];
        for( int j = i+1 ; j<= n ;j++){
            if( edg[ a[i] ][ a[j] ] == 1)
                F[j] = max( F[j], F[i]);
        }
        res= max( res, F[i]);
    }
    cout<< res;
    return 0;
}
