#include <bits/stdc++.h>
using namespace std;
int cnt=0;

// Ham tinh toan ham tien to (prefix function) cho chuoi P
vector<int> prefixFunction(const string& P) {
    int m = P.length();
    vector<int> pi(m + 1);
    pi[1] = 0; // Khoi tao gia tri dau tien cua ham tien to
    int k = 0; // Bien dem so ky tu khop
    for (int q = 2; q <= m; ++q) {
        // Neu ky tu hien tai khong khop, quay lai vi tri truoc do
        while (k > 0 && P[k] != P[q - 1]) {
            k = pi[k];
        }
        // Neu ky tu hien tai khop, tang bien dem
        if (P[k] == P[q - 1]) {
            k++;
        }
        pi[q] = k; // Gan gia tri cho ham tien to tai vi tri q
    }
    return pi; // Tra ve mang ham tien to
}

// Ham thuc hien thuat toan KMP de tim kiem chuoi P trong chuoi T
void KMPStringMatching(const string& T, const string& P) {
    int n = T.length();
    int m = P.length();
    vector<int> pi = prefixFunction(P); // Tinh toan ham tien to cho chuoi P
    int q = 0; // Bien dem so ky tu khop
    for (int i = 0; i < n; ++i) {
        // Neu ky tu hien tai khong khop, quay lai vi tri truoc do
        while (q > 0 && P[q] != T[i]) {
            q = pi[q];
        }
        // Neu ky tu hien tai khop, tang bien dem
        if (P[q] == T[i]) {
            q++;
        }
        // Neu tim thay chuoi P trong T
        if (q == m) {
            cnt++; // Tang bien dem so lan xuat hien
            q = pi[q]; // Quay lai vi tri tiep theo de tiep tuc tim kiem
        }
    }
}

int main() {
    string T, P;
    getline(cin, T); // Doc chuoi T tu dau vao
    getline(cin, P); // Doc chuoi P tu dau vao

    KMPStringMatching(P, T); // Thuc hien tim kiem chuoi P trong T
	cout<<cnt; // In ra so lan xuat hien cua chuoi P trong T
    return 0;
}