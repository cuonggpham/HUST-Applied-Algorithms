#include <bits/stdc++.h>
using namespace std;

int n, m, s, t; //n: so dinh, m: so canh
vector<int> adj[1001];
int parent[1001];
vector<bool> visit;

void input(){
    cin >> n >> m >> s >> t;
    for(int i=0; i<m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
    }
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end()); // Sap xep tang dan
    }
    memset(parent, -1, sizeof(parent));
    visit.resize(n+1, false);
}

bool bfs(int s, int t){
    queue<int> q;
    q.push(s);
    visit[s] = true;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v : adj[u]){
            if(!visit[v]){
                visit[v] = true;
                parent[v] = u;
                if(v ==t ) return true;
                q.push(v);
            }
        }
    }
    return true;
} 

void printPath(int s, int t) {
    if (!visit[t]) { 
        cout << "-1\n";
        return;
    }
    vector<int> path;
    for (int v = t; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end()); // reverse 

    for (int v : path) {
        cout << v << " ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 

    input();
    if(bfs(s, t)){
        printPath(s, t);
    }
    else{
        cout << "-1" << "\n";
    }

    return 0;
}