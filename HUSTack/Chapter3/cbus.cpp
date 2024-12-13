#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const int MAX_N = 1001;
const int INF = 1e9 + 1;

int n, Q;
int load=0, a[MAX_N][MAX_N], dmin = INF, x[MAX_N]; // x de luu hanh trinh;
bool visited[2*MAX_N];
int f = 0, f_best = INF;

void inp(){
    cin>>n>>Q;
    for(int i=0;i<=2*n;i++){
        for(int j=0;j<=2*n;j++){
            cin>>a[i][j];
            if(i!=j && a[i][j] < dmin) dmin = a[i][j];
        }
    }
    for(int i=0;i<=2*n;i++) visited[i]=false;
}

bool check(int v,int k){
    if(visited[v]) return false;
    if(v<=n){ // v la diem don
        if(load >= Q) return false; // xe day
    }else{ // v la diem tra
        if(!visited[v-n]) return false; // chua don
    }
    return true;
}

void Try(int k){
    for(int v=1; v<=2*n; v++){
        if(check(v,k)){
            x[k]=v;
            visited[v]=true;
            f = f+a[x[k-1]][x[k]];
            if(v <= n) load++; 
            else load--;
            
            if(k == 2*n){ // ket thuc hanh trinh
                f_best = min(f_best, f + a[x[2 * n]][0]); // tong quang duong = 
            } else if (f + dmin * (2 * n + 1 - k) < f_best) {  // (2n+1-k): so buoc con lai
                Try(k + 1);
            }
            // Hoan nguyen trang thai
            visited[v]=false;
            f= f-a[x[k-1]][x[k]];
            if(v<=n) load--; 
            else load++;
        }
    }
}

int main(){
    inp();
    x[0] = 0; // Diem xuat phat la 0
    Try(1); // Bat dau tu hanh trinh dau tien
    cout<<f_best<<endl;
    return 0;
}
