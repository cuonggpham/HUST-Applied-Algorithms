#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int X[100], n, k;

// X[i] ?
void display(){
    for(int i=1; i<=k; i++){
        cout << X[i] << " ";
    }
    cout << endl;
}

void Try(int i){
    for(int j=X[i-1]+1; j<=n-k+i; j++){
        X[i] = j;
        if(i==k){
            display();
        }
        else Try(i+1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    Try(1); 
}