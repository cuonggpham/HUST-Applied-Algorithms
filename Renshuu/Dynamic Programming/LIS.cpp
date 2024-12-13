#include <bits/stdc++.h>
using namespace std;

using ll = long long;

//L[i] = max(L[i], L[j]+1) 
// j thuoc [0, i-1], ai > aj
// O(N^2)
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // l[i] : do dai cua day con tang dai nhat ket thuc o chi so i
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    
    vector<int> L(n, 1);
    for(int i=0; i<n; i++){
        //L[i] : L[j] 
        for(int j=0; j<i; j++){
            if(a[i]>a[j]){
                L[i] = max(L[i], L[j]+1);
            }
        }
    }
    cout << *max_element(L.begin(), L.end()) << endl;

}