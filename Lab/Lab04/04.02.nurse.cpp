#include <bits/stdc++.h>
#define MAX 2000
using namespace std;

int N, K1, K2;

void solve() {
    int S0[MAX], S1[MAX];
    // S0: day ket thuc la 0, S1: day ket thuc la 1
    for (int i = 1; i <= N; i++) {
        S0[i] = 0;
        S1[i] = 0;
    }
    S0[1] = 1;  // Truong hop co ban: 1 cach de co day co do dai 1 ket thuc bang 0
    S1[K1] = 1; // Truong hop co ban: 1 cach de co day co do dai K1 ket thuc bang 1
    S0[0] = 1;  // Truong hop co ban: 1 cach de co day co do dai 0

    // Dien gia tri cho mang S0 va S1
    for (int i = K1 + 1; i <= N; i++) {
        S0[i] = S1[i - 1]; // Day co do dai i ket thuc bang 0 co the duoc tao bang cach them 0 vao day co do dai i-1 ket thuc bang 1
        S1[i] = 0; // Khoi tao S1[i] bang 0
        for (int j = K1; j <= K2; j++) {
            if (i - j >= 0)
                S1[i] += S0[i - j]; // Day co do dai i ket thuc bang 1 co the duoc tao bang cach them 1 vao day co do dai i-j ket thuc bang 0
        }
    }

    // Ket qua la tong cua cac day co do dai N ket thuc bang 0 va 1
    int rs = S0[N] + S1[N];
    cout << rs;
}

void input() {
    cin >> N >> K1 >> K2;
}

int main() {
    input();
    solve();
}