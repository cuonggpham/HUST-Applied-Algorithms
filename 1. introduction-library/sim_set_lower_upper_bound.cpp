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
        if(cmd == "insert"){
            int k; cin >> k;
            s.insert(k);
        }
        else if(cmd == "remove"){
            int k; cin >> k;
            s.erase(k);
        }
        else if(cmd == "min_greater_equal"){
            int k; cin >> k;
            auto p = s.lower_bound(k);
            if(p == s.end()){
                cout << "NULL" << "\n";
            }
            else{
                cout << *p << "\n";
            }
        }
        else if(cmd == "min_greater"){
            int k; cin >> k;
            auto p = s.upper_bound(k);
            if(p == s.end()){
                cout << "NULL" << "\n";
            }
            else{
                cout << *p << "\n";
            }
        }
    }
    return 0;
}