#include <bits/stdc++.h>
using namespace std;

int n, m, s; //n: so dinh, m: so canh
vector<int> adj[1001];
bool visited[10001];

void input(){
    cin >> n >> m >> s;
    for(int i=0; i<m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end(), greater<int>()); // Sap xep giam dan
    }
    memset(visited, false, sizeof(visited));
}

void dfs(int s){
    stack<int> S;
    S.push(s);

    while(!S.empty()){
        int u = S.top();
        S.pop();

        if(!visited[u]){
            visited[u] = true;
            cout << u << " ";
            for(int v : adj[u]){
                if(!visited[v]){
                    S.push(v);
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 

    input();
    dfs(s);

    return 0;
}