#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int X[100], n;

// X[i] ?

void Try(int i){
    for(int j=0; j<=1; j++){
        X[i] = j;
        if(i==n){
            for(int k=1; k<=n; k++){
                cout << X[k] << " ";
            }
            cout << endl;
        }
        else Try(i+1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    Try(1); 
}