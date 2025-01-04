#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, k;
vector<int> a;

int main()
{   
    int n, k;
    cin >> n >> k;
    a.resize(n); // Resize the vector to have n elements
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    int l=0;
    multiset<int> m;
    ll cnt=0;
    for(int r=0; r<n; r++)
    {   
        m.insert(a[r]);
        while(*m.rbegin() - *m.begin() > k){
            m.erase(m.find(a[l]));
            l++;
        }
        cnt += (r-l+1);
    }
    cout << cnt;
}
