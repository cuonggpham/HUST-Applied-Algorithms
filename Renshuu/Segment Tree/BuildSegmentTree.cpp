// build

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 20005;
int n, a[maxn], t[maxn*4];

void build(int v, int l, int r){
    if(l==r){
        t[v] = a[l]; // l=r: node leaf
    }
    else{
        int m = (l+r)/2;
        build(2*v, l, m);
        build(2*v+1, m+1, r);
        t[v] = t[2*v]+t[2*v+1];
    }
}

void update(int v, int l, int r, int pos, int val){
    if(l==r){
        t[v] = val;
    }
    else{
        int m = (l+r)/2;
        if(pos<=m){
            update(2*v, l, m, pos, val);
        }
        else{
            update(2*v+1, m+1, r, pos, val);
        }
        t[v]=t[2*v]+t[2*v+1];
    }
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    build(1, 0, n-1);
    for(int i=1; i<=15; i++){
        cout << t[i] << " ";
    }
    cout << '\n';
    update(1, 0, n-1, 4, 10);
    for(int i=1; i<=15; i++){
        cout << t[i] << " ";
    }
}