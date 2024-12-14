#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007

int N, M;
vector<string> grid;
string word;
vector<vector<bool>> visited;

bool is_valid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

bool check(int x, int y, int index) {
    return is_valid(x, y) && !visited[x][y] && grid[x][y] == word[index];
}

bool try_k(int x, int y, int index) {
    if (index == word.size()) {
        return true;
    }
    
    if (!check(x, y, index)) {
        return false;
    }
    
    visited[x][y] = true;
    
    // Move in 4 possible directions: up, down, left, right
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (auto [dx, dy] : directions) {
        if (try_k(x + dx, y + dy, index + 1)) {
            return true;
        }
    }
    
    visited[x][y] = false;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    grid.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> grid[i];
    }
    cin >> word;
    
    visited.assign(N, vector<bool>(M, false));
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (try_k(i, j, 0)) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    
    cout << "NO" << endl;
    return 0;
}