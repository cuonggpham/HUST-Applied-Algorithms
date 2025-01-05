#include <bits/stdc++.h>
using namespace std;

long long bestProfit = 0; 

bool conflictWith(vector<vector<bool>>& conflict, int stock, vector<int>& chosen) {
    for (int c: chosen) {
        if (conflict[stock][c]) return true;
    }
    return false;
}

void backtrack(int idx, int n1, int n2, int L, int M, vector<long long>& profit,
               vector<vector<bool>>& conflict, vector<int>& chosen, int cntTech, int cntRetail) {
    if (idx == n1 + n2) {
        if (cntTech >= M && cntRetail >= M) {
            long long sumP = 0;
            for (int s: chosen) sumP += profit[s];
            bestProfit = max(bestProfit, sumP);
        }
        return;
    }
    backtrack(idx + 1, n1, n2, L, M, profit, conflict, chosen, cntTech, cntRetail);
    if ((int)chosen.size() < L && !conflictWith(conflict, idx, chosen)) {
        chosen.push_back(idx);
        if (idx < n1) backtrack(idx + 1, n1, n2, L, M, profit, conflict, chosen, cntTech + 1, cntRetail);
        else backtrack(idx + 1, n1, n2, L, M, profit, conflict, chosen, cntTech, cntRetail + 1);
        chosen.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n1, n2, L; 
    cin >> n1 >> n2 >> L;
    vector<long long> profit(n1 + n2);
    for(int i = 0; i < n1 + n2; i++) {
        cin >> profit[i];
    }
    int M, P; 
    cin >> M >> P; 
    vector<pair<int,int>> conflicts(P);
    for(int i = 0; i < P; i++){
        cin >> conflicts[i].first >> conflicts[i].second;
        conflicts[i].first -= 1;
        conflicts[i].second -= 1;
    }
    vector<vector<bool>> conflictMatrix(n1 + n2, vector<bool>(n1 + n2, false));
    for (auto &pp: conflicts) {
        conflictMatrix[pp.first][pp.second] = true;
        conflictMatrix[pp.second][pp.first] = true;
    }
    for (int i = 0; i < n1; i++) {
        for (int j = i+1; j < n1; j++) {
            conflictMatrix[i][j] = true;
            conflictMatrix[j][i] = true;
        }
    }
    for (int i = n1; i < n1+n2; i++) {
        for (int j = i+1; j < n1+n2; j++) {
            conflictMatrix[i][j] = true;
            conflictMatrix[j][i] = true;
        }
    }
    vector<int> chosen;
    backtrack(0, n1, n2, L, M, profit, conflictMatrix, chosen, 0, 0);
    cout << bestProfit << "\n";
    return 0;
}
