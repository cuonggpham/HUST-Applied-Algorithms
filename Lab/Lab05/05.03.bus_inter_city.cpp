// Co n thanh pho 1, 2, ..., n. Giua 2 thanh pho i va j co the co 1 con duong (2 chieu) ket noi giua chung.
// Moi thanh pho i co tuyen buyt i voi C[i] la gia ve moi khi len xe va D[i] la so thanh pho toi da ma buyt i co the di den tren 1 hanh trinh di qua cac con duong ket noi.
// Hay tim cach di tu thanh pho 1 den thanh pho n voi so tien phai tra la it nhat.
// Input
// Dong 1: chua 2 so nguyen duong n va m trong do n la so thanh pho va m la so con duong ket noi cac thanh pho (1 <= n <= 5000, 1 <= m <= 10000)
// Dong i+1 (i = 1,2,...,n): chua 2 so nguyen duong C[i] va D[i] (1 <= C[i] <= 10000, 1 <= D[i] <= 100)
// Dong n+1+i (i = 1, 2, ..., m): chua 2 so nguyen duong i va j trong do giua thanh pho i va j co con duong ket noi
// Output
// So tien toi thieu phai bo ra de di buyt tu thanh pho 1 den thanh pho n

#include<bits/stdc++.h>

using namespace std;
int n, m;
int c[1005]; // Gia ve moi khi len xe buyt cua thanh pho i
int d[1005]; // So thanh pho toi da ma buyt i co the di den tren 1 hanh trinh
int edg[1005][1005]; // Ma tran ke luu tru cac con duong ket noi giua cac thanh pho
int dist[1005][1005]; // Ma tran luu tru chi phi di chuyen giua cac thanh pho
int D[1005]; // Mang luu tru khoang cach toi da tu thanh pho root den cac thanh pho khac
int minD[1005]; // Mang luu tru chi phi toi thieu de di tu thanh pho 1 den cac thanh pho khac

// Ham BFS de tim cac thanh pho co the di den tu thanh pho root trong pham vi D[root]
void BFS(int root) {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        D[i] = 1e6;
        dist[root][i] = 1e9;
    }
    D[root] = 0;
    q.push(root);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v = 1; v <= n; v++) {
            if (edg[u][v] == 1 && D[u] < D[v]) {
                D[v] = D[u] + 1;
                if (D[v] <= d[root]) {
                    dist[root][v] = c[root];
                    q.push(v);
                }
            }
        }
    }
}

// Ham Dijkstra de tim chi phi toi thieu de di tu thanh pho 1 den thanh pho n
void Dijk(int r) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 1; i <= n; i++) {
        minD[i] = 1e9;
    }
    minD[r] = 0;
    pq.push({minD[r], r});
    while (!pq.empty()) {
        pair<int, int> u = pq.top();
        pq.pop();
        if (u.first > minD[u.second]) continue;
        for (int v = 1; v <= n; v++) {
            if (minD[v] > u.first + dist[u.second][v]) {
                minD[v] = u.first + dist[u.second][v];
                pq.push({minD[v], v});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> c[i] >> d[i];
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        edg[u][v] = 1;
        edg[v][u] = 1;
    }

    // BFS
    for (int i = 1; i <= n; i++) {
        BFS(i);
    }

    // Dijkstra
    Dijk(1);
    cout << minD[n];
    return 0;
}

