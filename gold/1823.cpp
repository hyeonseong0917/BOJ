#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

#define ll long long

ll dp[2000+1][2000+1][2];

int main() {
	// your code goes here
	ll o=1;
	while(o--){
		// 1 3 1 5 2
		// 1 5 4 3 2
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		// dp[x][y]: x번째 턴에 y인덱스를 수확했을 때 최대
		// dp[x][y]=dp[x-i][y-1],dp[x-i][y+1]
		// 1<=i<x
		// dp[x][y]=dp[x-1][y-1]
		// dp[x][y]=dp[x-2][y-1]
		// dp[x][y]=dp[x-3][y-1]+(앞에 n-(x-3)개 psum)
		for(ll i=0;i<=2000;++i){
			for(ll j=0;j<=2000;++j){
				dp[i][j][0]=0;
				dp[i][j][1]=0;
			}
		}
		dp[1][0][0]=v[0];
		dp[1][n-1][1]=v[n-1];
		// dp[i][j]=이전 턴에 j+1날렸던가
		// 예전에 j+1날리고, 현재 앞에서 x개 날렸음
		// x는뭐지? dp[i-1][]
		// [1,3,1,5,2]
		for(ll i=1;i<=n;++i){
			for(ll j=0;j<n;++j){
				// i번째에 j날릴거임
				ll cur_num=i*v[j];
				if(j-1>=0){
					dp[i][j][0]=max(dp[i][j][0],dp[i-1][j-1][0]+cur_num);
				}
				if(j+1<n){
					dp[i][j][1]=max(dp[i][j][1],dp[i-1][j+1][1]+cur_num);
				}
				ll fst_idx=j-i+n+1;
				ll sed_idx=i+j-n-1;
				
				if(fst_idx>=0 && fst_idx<n){
					dp[i][j][0]=max(dp[i][j][0],dp[i-1][fst_idx][1]+cur_num);
				}
				if(sed_idx>=0 && sed_idx<n){
					dp[i][j][1]=max(dp[i][j][1],dp[i-1][sed_idx][0]+cur_num);
				}
			}
		}
		ll ans=0;
		// for(ll i=1;i<=n;++i){
		// 	for(ll j=0;j<n;++j){
		// 		cout<<i<<" "<<j<<" "<<0<<" "<<dp[i][j][0]<<"\n";
		// 		cout<<i<<" "<<j<<" "<<1<<" "<<dp[i][j][1]<<"\n";
		// 	}
		// }
		for(ll i=0;i<n;++i){
			// cout<<i<<" "<<dp[n][i]<<endl;
			ans=max(ans,max(dp[n][i][0],dp[n][i][1]));
		}
		cout<<ans;

	}
	return 0;
}