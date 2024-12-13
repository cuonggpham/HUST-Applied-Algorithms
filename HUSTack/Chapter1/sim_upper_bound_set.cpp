#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    set<int> s;
    for(int i=0; i<n; i++){
        int tmp; cin >> tmp;
        s.insert(tmp);
    }

    string cmd;
    while(cin >> cmd && cmd != "#"){
        if(cmd == "next"){
            int k; cin >> k;
            auto p = s.upper_bound(k);
            if(p == s.end()){
                cout << "-1" << "\n";
            }
            else{
                cout << *p << "\n";
            }
        }
    }
    return 0;
}