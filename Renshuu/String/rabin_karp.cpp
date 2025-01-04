#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

// Ham tinh ma hash cua chuoi pattern p
int hashcodep(const string &p) {
    ll c = 0;
    for (char ch : p) {
        c = (c * 256 + ch) % mod; // Tinh ma hash bang cach nhan voi 256 va cong ky tu hien tai, sau do lay modulo
    }
    return c;
}

// Thuat toan Rabin-Karp de dem so lan xuat hien cua P trong T
int Rabin_Karp(string P, string T) {
    int cnt = 0, N = T.length(), M = P.length();
    if (M > N) return 0; // Neu pattern dai hon text thi tra ve 0

    int codeP = hashcodep(P); // Ma hash cua pattern P

    ll codeT = 0, e = 1;
    for (int i = 0; i < M; ++i) {
        codeT = (codeT * 256 + T[i]) % mod; // Tinh ma hash cho chuoi con dau tien cua T
        if (i > 0) e = (e * 256) % mod;   // Tinh 256^(M-1) % mod
    }

    for (int s = 0; s <= N - M; ++s) {
        if (codeT == codeP) { // Neu ma hash trung khop
            if (T.substr(s, M) == P) { // Kiem tra tung ky tu bang cach so sanh chuoi con
                cnt++;
            }
        }
        if (s < N - M) {
            codeT = (codeT - T[s] * e % mod + mod) % mod; // Loai bo ky tu dau tien cua cua so hien tai
            codeT = (codeT * 256 + T[s + M]) % mod;       // Them ky tu moi vao cuoi cua so
        }
    }
    return cnt; // Tra ve so lan xuat hien cua P trong T
}

int main() {
    string P, T;
    getline(cin, P); // Doc chuoi pattern P
    getline(cin, T); // Doc chuoi text T
    cout << Rabin_Karp(P, T) << endl; // In ra ket qua
    return 0;
}
