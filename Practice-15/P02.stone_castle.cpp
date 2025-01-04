// Ban la mot kien truc su xay dung phao dai va can cat khoi da hinh hop chu nhat lon sao cho:
// Tong the tich da lang phi la it nhat (phan da khong dung duoc).
// Khoi da co the duoc cat theo chieu dai, rong, hoac cao va chi cat xuyen suot (chia thanh 2 phan nho hon).
// Cac khoi da cat ra co the xoay theo moi huong de phu hop voi yeu cau (AxBxC tuong duong voi BxAxC, BxCxA,...).
// Dau vao:
// So luong test case T (1 ≤ T ≤ 10).
// Moi test case gom:
// Kich thuoc khoi da ban dau L, W, H (1 ≤ L, W, H ≤ 100).
// So luong khoi da mong muon N (0 < N ≤ 50).
// Danh sach N khoi da mong muon, moi khoi co kich thuoc Li, Wi, Hi (1 ≤ Li ≤ L, 1 ≤ Wi ≤ W, 1 ≤ Hi ≤ H).
// Ket qua:
// Voi moi test case, in ra tong the tich da lang phi nho nhat sau khi cat.

#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
	int l,w,h;
	cin>>l>>w>>h;
	int n;
	cin>>n;
	int dp[l+5][w+5][h+5];
	
	
	vector<vector<int>> blocks;
	for(int i=0; i<n; i++){
		int x,y,z; cin >> x >> y>>z;
		blocks.push_back({x,y,z});
	}
	for(int lo=0; lo<=l; lo++){
		for(int wo=0; wo<=w; wo++){
			for(int ho=0; ho<=h; ho++){
				if(lo==0 || wo==0 || ho == 0) dp[lo][wo][ho] = 0;
				else dp[lo][wo][ho] = lo*ho*wo;
			}
		}
	}
	for(int lo = 1; lo <= l; lo++){
		for(int wo = 1; wo <= w; wo++){
			for(int ho = 1; ho <= h; ho++){
				// check fit
				for(vector<int> block : blocks){
					int x = block[0];
					int y = block[1];
					int z = block[2];
					vector<vector<int>> cs;
					cs.push_back({x,y,z});
					cs.push_back({x,z,y});
					cs.push_back({y,x,z});
					cs.push_back({y,z,x});
					cs.push_back({z,x,y});
					cs.push_back({z,y,x});
				
					for(int j=0; j<6; j++){
						if(lo == cs[j][0] && wo == cs[j][1] && ho == cs[j][2]){
							dp[lo][wo][ho] = 0;
						}
					}
				}
				// else cut
				for(int x=1; x<=lo; x++) dp[lo][wo][ho] = min(dp[lo][wo][ho], dp[lo-x][wo][ho] + dp[x][wo][ho]);
				for(int y=1; y<=wo; y++) dp[lo][wo][ho] = min(dp[lo][wo][ho], dp[lo][wo-y][ho] + dp[lo][y][ho]);
				for(int z=1; z<=ho; z++) dp[lo][wo][ho] = min(dp[lo][wo][ho], dp[lo][wo][z] + dp[lo][wo][ho-z]);
				
			}
		}
	}
	cout << dp[l][w][h] << '\n';

}
main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}
