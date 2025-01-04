#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, s;
vector<int> a;

int main()
{
    cin >> n >> s;
    a.resize(n); // Resize the vector to have n elements
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    int l=0;
    ll curr_sum =0;
    ll cnt=0;
    for(int r=0; r<n; r++)
    {
        curr_sum += a[r];
        while(curr_sum >= s)
        {
            cnt+= n-r;
            curr_sum -= a[l];
            l++;
        }
    }
    cout << cnt;
}
