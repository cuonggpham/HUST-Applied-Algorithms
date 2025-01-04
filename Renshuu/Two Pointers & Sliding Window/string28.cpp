#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    string s;
    cin >> s;
    int x, y;
    cin >> x >> y;
    
    int cnt2=0, cnt8=0;
    int n=s.length();
    int l=0;
    int maxx=0;
    for(int r=0; r<n; r++){
        if(s[r]=='2') cnt2++;
        if(s[r]=='8') cnt8++;
        while(cnt2 > x || cnt8 > y){
            if(s[l]=='2') cnt2--;
            if(s[l]=='8') cnt8--;
            l++;
        }
        maxx = max(maxx, r-l+1);        
    }
    cout << "\n" << maxx;
}
