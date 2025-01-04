#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s, t;
    cin >> s;
    cin >> t;
    int n = s.length();

    unordered_map<char, int> cnt;
    for(char c : t) cnt[c]++;
    unordered_map<char, int> cnt1;
    
    int l=0;
    int minn=INT_MAX; 
    int check = 0;
    int start = 0;
    
    for(int r=0; r<n; r++) {
        cnt1[s[r]]++;
        if(cnt.count(s[r]) && cnt1[s[r]] == cnt[s[r]]){
            check++;
        }
        while(check == cnt.size()){
            if(minn > r-l+1){
                minn = r-l+1;
                start = l;
            }
            cnt1[s[l]]--;
            if(cnt.count(s[l]) && cnt1[s[l]] < cnt[s[l]]){
                check--;
            }
            l++;
        }
    }

    if(minn == INT_MAX){ 
        cout << "-1";
    } else {
        for(int i=start; i< start+minn; i++){ 
            cout << s[i];
        }
    }

    return 0;
}
