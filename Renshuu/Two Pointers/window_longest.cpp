#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    int n = s.length();

    unordered_set<char> seen;
    int l=0;
    int maxx=-1e9+1;
    for(int r=0; r<n; r++) {
        while(seen.count(s[r])){
            seen.erase(s[l]);
            l++;
        }
        seen.insert(s[r]);
        maxx = max(maxx, r-l+1);
    }
    cout << maxx;

    return 0;
}
