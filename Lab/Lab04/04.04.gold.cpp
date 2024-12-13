#include<bits/stdc++.h>

using namespace std;

int n, L1, L2;
int a[1000005] ={};
int F[1000005] ={};

deque<int > dq;
int res = -1e9;

int main(){
    cin>> n >> L1 >> L2; // Nhap gia tri n, L1, L2
    for( int i = 1; i <= n; i++){
        cin>>a[i]; // Nhap gia tri cua mang a
        if( i > L1 ){
            // Loai bo cac phan tu khong can thiet trong deque
            while( !dq.empty() && F[ dq.back() ] < F[ i-L1 ] ){
                dq.pop_back(); // Loai bo phan tu o cuoi deque neu no nho hon F[i-L1]
            }
            while(  !dq.empty() && dq.front() < i - L2){
                dq.pop_front(); // Loai bo phan tu o dau deque neu no nam ngoai khoang [i-L2, i-L1]
            }
            dq.push_back(i-L1); // Them chi so i-L1 vao deque

            F[i] = F[dq.front()] + a[i]; // Tinh gia tri F[i]
        }
        else{
            F[i] = a[i];
        }
        res = max( res, F[i]);
    }
    for(int i=1; i<=n; i++) cout << F[i];
    cout<< res;
}
