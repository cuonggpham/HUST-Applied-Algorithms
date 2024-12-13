#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e4+5;
int mem[N];

int fib(int n){
    if(n <= 2) return 1;
    if (mem[n] != -1) return mem[n];
    int res = fib(n-1) + fib(n-2);
    mem[n] = res;
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(mem, -1, sizeof(mem));
    int k;
    cin >> k;
    cout << fib(k);
}