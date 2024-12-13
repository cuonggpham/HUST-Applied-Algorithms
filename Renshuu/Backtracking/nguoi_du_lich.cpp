#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int c[100][100], n, ans = INT_MAX;
int X[100]; // mang luu tru hanh trinh hien tai
int visited[100];

void input(){
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> c[i][j];
        }
    }
}

void Try(int i, int cur){
    for(int j=1; j<=n; j++){
        if(!visited[j]){
            X[i]=j;
            visited[j]=1;
            int truoc = X[i-1], htai = X[i];
            cur += c[truoc][htai];
            // neu da di het cac diem -> cap nhat ans
            if(i == n){
                ans = min(ans, cur + c[1][X[i]]);
            }

            else 
                Try(i+1, cur);

            visited[j] = 0;
            cur -= c[truoc][htai];  // khoi phuc trang thai
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    X[1]=1; // hanh trinh bat dau tu diem 1
    Try(2, 0);
    cout << ans << endl;
}