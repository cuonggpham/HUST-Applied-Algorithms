// Cho mot do thi vo huong chua N dinh va M canh, tim tat ca cac diem khop va cac canh cau trong do thi.
// Dau vao
// Dong dau tien gom hai so nguyen cach nhau boi dau cach bieu dien N va M,
// M dong tiep theo, moi dong chua hai so nguyen X va Y bieu dien co mot canh giua X va Y.
// Dau ra
// Mot dong gom hai so nguyen bieu dien so luong diem khop va so luong canh cau.

#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const int maxn=1e5; 
int n,m,tmp=0; 
vector<int> adj[maxn]; 
int disc[maxn],low[maxn]; 
bool visited[maxn];
vector<pair<int,int>> bridge; 

void inp(){
    cin>>n>>m; 
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y; 
        adj[x].push_back(y); 
        adj[y].push_back(x);
    }
    memset(visited,false,sizeof(visited)); 
}

void dfs_canh_cau(int u,int par){
    visited[u]=true; 
    disc[u]=low[u]=++tmp;
    for(int v:adj[u]){ 
        if(v==par) continue; // Neu v la cha cua u thi bo qua
        if(!visited[v]){ 
            dfs_canh_cau(v,u); 
            low[u]=min(low[u],low[v]); 
            if(disc[u]<low[v]){ // Kiem tra dieu kien de (u,v) la canh cau
                bridge.push_back({u,v});
            }
        }else{
            low[u]=min(low[u],disc[v]); 
        }
    }
}

int main(){
    inp(); 
    int cc=0; 
    tmp=0;
    memset(visited,false,sizeof(visited)); 
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs_canh_cau(i,-1); 
        }
    }
    for(auto it:bridge){
        // cout<<it.first<<" "<<it.second;
        cc++; 
    }
    cout<<cc; 
}