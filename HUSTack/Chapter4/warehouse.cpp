#include<bits/stdc++.h>

using namespace std;
int n, T ,D;
int a[1005]; // Mang a luu tru gia tri cua cac vat pham
int t[1005]; // Mang t luu tru thoi gian can thiet de chon cac vat pham

int F[1005][105] = {}; // Mang F luu tru gia tri toi uu tai moi buoc

int res = -1e9;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>T>>D;

    for( int i = 1;i <= n;i++) cin>> a[i];
    for( int i = 1;i <= n;i++) cin>> t[i];

    for( int i = 1 ; i<= n ;i++){
        for( int k = 1 ; k <= T; k++){
            if( k < t[i] ){
                // Neu thoi gian k nho hon thoi gian can thiet t[i] thi khong the chon vat pham nay
                F[i][k] = 0;
            }else{
                // Khoi tao gia tri ban dau cua F[i][k] la gia tri cua vat pham a[i]
                F[i][k] = a[i];
                for( int j = 1 ; j <= D && i - j >= 0 ; j++){
                    // Cap nhat gia tri F[i][k] bang cach chon vat pham tu cac vi tri truoc do trong khoang D
                    F[i][k] = max( F[i][k] , F[i-j][k-t[i]] +a[i] );
                }
            }
            // Cap nhat ket qua toi uu
            res = max ( res, F[i][k]);
        }
    }
    cout<<res;
    
    return 0;
}
