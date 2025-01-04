#include <bits/stdc++.h>
using namespace std;

int n, m, s, t; //n: so dinh, m: so canh
vector<int> adj[1001];
int parent[1001];
vector<bool> visit;

void input(){
    cin >> n >> m >> s;
    for(int i=0; i<m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        // adj[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end()); // Sap xep tang dan
    }
    memset(parent, -1, sizeof(parent));
    visit.resize(n+1, false);
}

void bfs(int s){
    queue<int> q;
    q.push(s);
    visit[s] = true;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout << u << " ";

        for(int v : adj[u]){
            if(!visit[v]){
                visit[v] = true;
                q.push(v);
            }
        }
    }
} 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 

    input();
    bfs(s);

    return 0;
}