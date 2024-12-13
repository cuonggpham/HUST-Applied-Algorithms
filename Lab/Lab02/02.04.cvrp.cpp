#include <bits/stdc++.h>
using namespace std;

const int N = 20;  // Gioi han so diem giao hang
const int oo = 1e9;  // Gia tri vo cung de khoi tao
int n, K, Q, cmin = oo;  // So diem giao hang, so xe, tai trong moi xe, chi phi nho nhat
int d[N], C[N][N];  // Trong luong moi diem va ma tran chi phi
int x[N], y[N], load[N];  // Luu cac diem xe ghe tham, diem dau tien moi xe, tai trong xe
int segments = 0, f = 0, fOpt = oo, nbR;  // So doan duong, chi phi hien tai, chi phi toi uu, so diem da ghe tham
bool visited[N];  // Danh dau diem da duoc ghe tham

void input() {
    cin >> n >> K >> Q;  // Doc vao so diem giao hang, so xe, tai trong xe
    for (int i = 1; i <= n; i++)
        cin >> d[i];  // Doc vao trong luong tung diem giao hang
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++) {
            cin >> C[i][j];  // Doc vao ma tran chi phi
            if (i != j) cmin = min(cmin, C[i][j]);  // Tim chi phi nho nhat giua hai diem bat ky
        }
}

// Kiem tra diem v co the la diem dau tien cua xe k hay khong
bool checkY(int v, int k) {
    if (v == 0) return true;  // Neu v = 0 (ve diem xuat phat), hop le
    if (d[v] > Q) return false;  // Neu trong luong vuot qua tai trong xe, khong hop le
    if (visited[v]) return false;  // Neu diem da ghe tham, khong hop le
    return true;
}

// Kiem tra diem v co the la diem tiep theo cua xe k hay khong
bool checkX(int v, int k) {
    if (v > 0 && visited[v]) return false;  // Neu diem da ghe tham, khong hop le
    if (load[k] + d[v] > Q) return false;  // Neu vuot qua tai trong xe, khong hop le
    return true;
}

// Cap nhat chi phi toi uu neu tim duoc chi phi nho hon
void updateBest() {
    if (f < fOpt) fOpt = f;
}

// Ham quay lui de tim cac diem tiep theo cho xe k
void TRY_X(int s, int k) {
    if (s == 0) {  // Neu xe tro ve diem xuat phat
        if (k < K) TRY_X(y[k + 1], k + 1);  // Chuyen sang xe tiep theo
        return;
    }

    for (int v = 0; v <= n; v++) {  // Duyet tat ca cac diem
        if (checkX(v, k)) {  // Neu diem v hop le
            x[s] = v;  // Ghi nhan diem v la diem tiep theo
            visited[v] = true;  // Danh dau diem da ghe tham
            f += C[s][v];  // Cap nhat chi phi
            segments++;  // Tang so doan duong
            load[k] += d[v];  // Cap nhat tai trong xe

            if (v > 0) {
                // Neu chua vuot qua chi phi toi uu, tiep tuc quay lui
                if (f + (n + nbR - segments) * cmin < fOpt)
                    TRY_X(v, k);
            } else {
                if (k == K) {
                    if (segments == n + nbR) updateBest();  // Cap nhat ket qua neu tat ca cac diem da ghe tham
                } else {
                    // Chuyen sang xe tiep theo neu chi phi hop le
                    if (f + (n + nbR - segments) * cmin < fOpt)
                        TRY_X(y[k + 1], k + 1);
                }
            }

            // Quay lui de thu diem khac
            visited[v] = false;
            f -= C[s][v];
            segments--;
            load[k] -= d[v];
        }
    }
}

// Ham quay lui de tim diem dau tien cho moi xe
void TRY_Y(int k) {
    int s = 0;
    if (y[k - 1] > 0) s = y[k - 1] + 1;  // Bat dau tu diem lon hon diem truoc do

    for (int v = s; v <= n; v++) {  // Duyet tat ca cac diem
        if (checkY(v, k)) {  // Neu diem v hop le
            y[k] = v;  // Ghi nhan diem v la diem dau tien cua xe k
            if (v > 0) segments++;  // Tang so doan duong neu la diem giao hang
            f += C[0][v];  // Cap nhat chi phi
            visited[v] = true;  // Danh dau diem da ghe tham
            load[k] += d[v];  // Cap nhat tai trong xe

            if (k < K) TRY_Y(k + 1);  // Chuyen sang xe ke tiep
            else {
                nbR = segments;  // Luu so diem da ghe tham
                TRY_X(y[1], 1);  // Bat dau tim cac diem tiep theo
            }

            // Quay lui de thu diem khac
            if (v > 0) segments--;
            f -= C[0][v];
            visited[v] = false;
            load[k] -= d[v];
        }
    }
}

int main() {
    input();  // Doc du lieu dau vao
    y[0] = 0; d[0] = 0;  // Khoi tao diem bat dau
    TRY_Y(1);  // Bat dau tim diem dau tien cho cac xe
    cout << fOpt << endl;  // In ra chi phi toi uu
    return 0;
}
