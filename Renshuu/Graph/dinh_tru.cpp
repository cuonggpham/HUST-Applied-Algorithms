#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const int maxn=1e5; 
int n,m,tmp=0; 
vector<int> adj[maxn]; 
int disc[maxn],low[maxn]; 
bool visited[maxn],ap[maxn];

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
            if(par!=-1 && disc[u]<=low[x]){ 
                ap[u]=true; 
            }
        }else{
            low[u]=min(low[u],disc[x]); 
        } 
    }
    if(par == -1 && child > 1) ap[u]=true;
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
}