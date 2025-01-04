// Cho do thi co huong G=(V,E) voi V={1,...,N} la tap cac dinh va E la tap cac cung. Tinh so thanh phan lien thong manh cua G.
// Input
// Dong 1: hai so nguyen duong N va M (1 <= N <= 10^5, 1 <= M <= 10^6)
// Dong i+1 (i=1,...,M): chua hai so nguyen duong u va v la diem dau va diem cuoi cua cung thu i
// Output
// In ra so thanh phan lien thong manh cua G

#include<bits/stdc++.h>
using namespace std;

const int MAX_NODES = 1e5 + 1;
const int MAX_EDGES = 1e6 + 1;
int numNodes, numEdges;
bool visited[MAX_NODES];
vector<int> adj[MAX_NODES]; // danh sach ke cho do thi goc
vector<int> adjReverse[MAX_NODES]; // danh sach ke cho do thi dao nguoc
int sccCount = 0; // so thanh phan lien thong manh
stack<int> nodeStack;

void input() {
    cin >> numNodes >> numEdges;
    for (int i = 0; i < numEdges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // them cung (u, v) vao do thi goc
        adjReverse[v].push_back(u); // them cung (v, u) vao do thi dao nguoc
    }
    memset(visited, false, sizeof(visited)); // khoi tao mang visited
}

void dfs1(int u) {
    // DFS tren do thi goc
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs1(v);
        }
    }
    nodeStack.push(u); // day dinh u vao stack sau khi da tham het cac dinh ke
}

void dfs2(int u) {
    // DFS tren do thi dao nguoc
    visited[u] = true;
    for (int v : adjReverse[u]) {
        if (!visited[v]) {
            dfs2(v);
        }
    }
}

void solve() {
    // Thuc hien DFS tren do thi goc de day cac dinh vao stack
    for (int i = 1; i <= numNodes; i++) {
        if (!visited[i]) {
            dfs1(i);
        }
    }
    memset(visited, false, sizeof(visited)); // reset mang visited
    // Xu ly cac dinh theo thu tu trong stack
    while (!nodeStack.empty()) {
        int u = nodeStack.top();
        nodeStack.pop();
        if (!visited[u]) {
            sccCount++; 
            dfs2(u); 
        }
    }
}

int main() {
    input(); 
    solve(); 
    cout << sccCount;
}