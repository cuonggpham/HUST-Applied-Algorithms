// Bai toan: Co n cong viec 1, ..., n va m nhan vien 1, ..., m. T(i) la tap cac nhan vien co the thuc hien cong viec i (i=1, ..., n).
// Tinh toan viec phan cong nhan vien cho cong viec sao cho moi cong viec duoc giao cho toi da mot nhan vien va moi nhan vien khong hon 1 task

#include<bits/stdc++.h>
using namespace std;

const int N=10005; 
vector<int> T[N]; // luu danh sach cac nhan vien co the thuc hien cong viec
int match[N],visited[N]; 

bool dfs(int u){
    for(int v:T[u]){
        if(!visited[v]){ 
            visited[v]=true; 
            if(match[v]==-1 || dfs(match[v])){ // Neu nhan vien v chua duoc ghep hoac co the ghep lai
                match[v]=u; // Ghep nhan vien v voi cong viec u
                return true; 
            }
        }
    }
    return false; 
}

// Ham max_matching de tim so luong ghep cuc dai
void max_matching(int n,int m){
    int cnt=0; 
    memset(match,-1,sizeof(match)); 
    for(int u=1;u<=n;u++){ 
        memset(visited,false,sizeof(visited)); 
        if(dfs(u)){ 
            cnt++; 
        }
    }
    cout<<cnt; // In ra so luong ghep cuc dai
}

int main(){
    int n,m;cin>>n>>m; 
    for(int i=1;i<=n;i++){ 
        int k;cin>>k; 
        for(int j=0;j<k;j++){ 
            int t;cin>>t; 
            T[i].push_back(t); 
        }
    }
    max_matching(n,m); 
    return 0; 
}
