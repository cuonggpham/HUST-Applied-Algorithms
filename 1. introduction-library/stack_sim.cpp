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

    stack<int> s;
    string cmd;

    while (cin >> cmd && cmd != "#") {
        if(cmd == "PUSH"){
            int a;
            cin >> a;
            s.push(a);
        }
        else if(cmd == "POP"){
            if(!s.empty()){
                cout << s.top() << endl;
                s.pop();
            }
            else cout << "NULL" << endl;
        }
    }
    return 0;
}