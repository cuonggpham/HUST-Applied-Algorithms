#include <bits/stdc++.h>
using namespace std;

int n, m; //n: so dinh, m: so canh
vector<int> adj[1001];
bool visited[1001];

void input(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end()); 
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
            for(int v : adj[u]){
                if(!visited[v]){
                    S.push(v);
                }
            }
        }
    }
}

int count_lt(){
    int cnt=0;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            cnt++;
            dfs(i);
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 

    input();
    cout << count_lt() << "\n";

    return 0;
}