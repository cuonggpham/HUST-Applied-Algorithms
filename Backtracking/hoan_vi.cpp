#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int X[100], n;
int used[100];

// X[i] ?
void display(){
    for(int i=1; i<=n; i++){
        cout << X[i] << " ";
    }
    cout << endl;
}

void Try(int i){
    for(int j=1; j<=n; j++){
        if(used[j]==0){
            X[i] = j;
            used[j]=1;
            if(i==n){
                display();
            }
            else Try(i+1);
            // backtrack
            used[j]=0;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    Try(1); 
}