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
int n,m,tmp=0; // n: so dinh, m: so canh, tmp: bien dem thoi gian
vector<int> adj[maxn]; 
int disc[maxn],low[maxn]; // disc: thoi gian phat hien, low: thoi gian thap nhat co the dat toi
bool visited[maxn],ap[maxn];//ap: dinh tru
vector<pair<int,int>> bridge; 

void inp(){
    cin>>n>>m; 
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y; 
        adj[x].push_back(y); 
        adj[y].push_back(x);
    }
    memset(visited,false,sizeof(visited)); 
    memset(ap,false,sizeof(ap)); 
}

void dfs_dinh_tru(int u,int par){
    visited[u]=true; 
    disc[u]=low[u]=++tmp;
    int child=0; // Dem so luong con cua u
    for(int x:adj[u]){ 
        if(!visited[x]){ 
            dfs_dinh_tru(x,u); 
            ++child; 
            low[u]=min(low[u],low[x]); 
            if(par!=-1 && disc[u]<=low[x]){ // Kiem tra dieu kien de u la diem khop
                ap[u]=true; 
            }
        }else{
            low[u]=min(low[u],disc[x]); 
        } 
    }
    if(par == -1 && child > 1) ap[u]=true; // Neu u la goc va co nhieu hon 1 con thi u la diem khop
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
    int dt=0,cc=0; 
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs_dinh_tru(i,-1); 
        }
    }
    for(int i=1;i<=n;i++){
        if(ap[i]){
            // cout<<i<<" ";
            dt++; 
        }
    }
    cout<<dt<<" "; 
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