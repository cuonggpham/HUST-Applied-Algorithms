#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> s;
    string command;

    while (cin >> command && command != "#") {
        if(command == "PUSH"){
            int a;
            cin >> a;
            s.push(a);
        }
        else if(command == "POP"){
            if(!s.empty()){
                cout << s.top() << endl;
                s.pop();
            }
            else cout << "NULL" << endl;
        }
    }
    return 0;
}
