#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    int n = s.length();
    unordered_map<char, int> fre;
    for(int i=0; i<n; i++) fre[s[i]]++;

    unordered_map<char, int> fre1;
    int l=0;
    int minn=1e9+1;
    for(int r=0; r<n; r++) {
        fre1[s[r]]++;
        while(fre1.size() == fre.size()){
            minn = min(minn, r-l+1);
            fre1[s[l]]--;
            if(fre1.empty()){
                fre1.erase(s[l]);
            }
            l++;
        }
    }
    cout << minn;

    return 0;
}
