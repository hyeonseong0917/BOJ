#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

ll dp[100+1][300+1][300+1];

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		// 1358
		// 치즈버거 요구개수 감자튀김 요구개수
		// 최대 몇 개의 주문 처리?
		ll N,M,K;
		cin>>N>>M>>K;
		for(ll i=0;i<N;++i){
			for(ll j=0;j<M;++j){
				for(ll k=0;k<K;++k){
					dp[i][j][k]=0;
				}
			}
		}
		vector<pair<ll,ll>> v;
		for(ll i=0;i<N;++i){
			ll x,y;
			cin>>x>>y;
			v.push_back({x,y});
		}
		// 현재 햄버거 m개, 감튀 k개 있음
		// 최대 몇 개의 주문을 처리할 수 있을까?
		// dp[i][x][y]: i인덱스에서 햄버거 x개, 감튀 y개
		// 썼을 때 처리할 수 있는 주문의 양
		dp[0][v[0].first][v[0].second]=1;
		ll ans=0;
		if(M>=v[0].first && K>=v[0].second){
			ans=1;
		}
		for(ll i=1;i<N;++i){
			for(ll j=0;j<=M;++j){
				for(ll k=0;k<=K;++k){
					dp[i][j][k]=dp[i-1][j][k];
					if(j-v[i].first>=0 && k-v[i].second>=0){
						dp[i][j][k]=max(dp[i][j][k],1+dp[i-1][j-v[i].first][k-v[i].second]);
					}
					ans=max(ans,dp[i][j][k]);
				}
			}
		}
		cout<<ans;
		// cout<<dp[2][3][4]<<endl;
		// cout<<dp[N-1][M][K];
	}
	return 0;
}