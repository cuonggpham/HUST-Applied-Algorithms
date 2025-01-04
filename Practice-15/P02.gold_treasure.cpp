// Ban can tim duong di toi uu de thu thap tong luong vang lon nhat tu cac kho bau trong mot vuong quoc, tuan theo quy tac:
// Quy tac di chuyen:
// Bat dau tu (0,0).
// Chi duoc di chuyen ve phia "mat troi moc", tuc la den cac diem (xj, yj) thoa man xi <= xj va yi <= yj.
// Dau vao:
// So luong kho bau n (1 <= n <= 103).
// Moi kho bau co toa do (x, y) va luong vang c (1 <= x, y, c <= 109).
// Dau ra:
// Tong luong vang lon nhat co the thu thap duoc.

#include <bits/stdc++.h>
using namespace std;

int main() 
{ 
    int n;
    cin >> n; 
    int a[1005][1005] = {0}; 
    long long b[1005]; // luong vang toi da co the thu thap tai moi toa do
    int x, y, z, mx = 0, my = 0; // mx, my la toa do lon nhat tren truc x va y
    long long ans = 0; 

    for (int i = 0; i < n; i++) {
        cin >> x >> y >> z;
        mx = max(mx, x); 
        my = max(my, y); 
        a[x][y] += z; 
    }

    vector<pair<int, int>> coor; // cac toa do co kho bau

    for (int i = 0; i <= mx; i++) {
        for (int j = 0; j <= my; j++) {
            if (a[i][j] > 0) {
                coor.push_back(make_pair(i, j));  
            }
        }
    }
    
    n = coor.size(); 
    b[0] = a[coor[0].first][coor[0].second]; // Khoi tao luong vang tai toa do dau tien
    // Tinh toan tong luong vang toi da co the thu thap tai moi toa do
    for (int i = 1; i < n; i++) {
        b[i] = a[coor[i].first][coor[i].second];
        for (int j = 0; j < i; j++) {
            if (coor[i].second >= coor[j].second) {
                b[i] = max(b[i], b[j] + a[coor[i].first][coor[i].second]);
            }
        }
        ans = max(ans, b[i]); 
    }
    cout << ans;
}
