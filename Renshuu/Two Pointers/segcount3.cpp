#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, k;
vector<int> a;

int main()
{   
    cin >> n >> k;
    a.resize(n); // Resize the vector to have n elements
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    int l=0;
    unordered_map<int, int> fre;
    ll cnt=0;
    for(int r=0; r<n; r++)
    {   
        fre[a[r]]++;
        while(fre.size() > k){
            fre[a[l]]--;
            if(fre[a[l]] == 0){
                fre.erase(a[l]);
            }
            l++;
        }
        cnt += (r-l+1);
    }
    cout << cnt;
}
