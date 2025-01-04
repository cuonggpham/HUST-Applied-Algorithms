#include<bits/stdc++.h>
using namespace std;

const int maxP = 256;
int last[maxP];

// Ham tinh toan vi tri xuat hien cuoi cung cua cac ky tu trong chuoi p
void computeLast(string p){
    // Khoi tao mang last voi gia tri 0
    for(int c = 0; c<=255; c++){
        last[c] = 0;
    }
    int k = p.length();
    // Cap nhat vi tri xuat hien cuoi cung cua tung ky tu trong chuoi p
    for(int i = k-1; i >= 0; i--){
        if(last[p[i]] == 0) last[p[i]] = i;
    }
}

// Ham Boyer-Moore de tim so lan xuat hien cua chuoi P trong chuoi T
int boyerMoore(string P, string T){
    computeLast(P); // Tinh toan vi tri xuat hien cuoi cung cua cac ky tu trong P
    int s = 0, cnt = 0, N = T.length(), M = P.length();
    // Duyet qua chuoi T de tim chuoi P
    while(s <= N - M){
        int j = M - 1;
        // So sanh tung ky tu tu cuoi ve dau cua P voi T
        while(j >= 0 && T[j + s] == P[j]){
            j = j - 1;
        }
        // Neu tim thay chuoi P trong T
        if(j == -1){
            cnt++; s = s + 1; // Tang bien dem va dich sang phai 1 vi tri
        } else {
            int k = last[T[j + s]]; // Lay vi tri xuat hien cuoi cung cua ky tu T[j + s] trong P
            // Tinh toan buoc nhay
            s = s + (j - k > 1 ? j - k : 1);
        }
    }
    return cnt; // Tra ve so lan xuat hien cua P trong T
}

int main(){
    string P, T;
    getline(cin, P); // Nhap chuoi P
    getline(cin, T); // Nhap chuoi T
    cout << boyerMoore(P, T); // In ra so lan xuat hien cua P trong T
    return 0;
}