#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;

#define ll long long


int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n,m;
		cin>>n>>m;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		vector<ll> g[n];
		for(ll i=0;i<m;++i){
			ll x,y;
			cin>>x>>y;
			--x;
			--y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		// dp[x][y]: x번 섬에 y번째로 이동했을 때 가장 낮은 섬의 높이
		// dp[x][y][z]: x번 섬에서 y번 이동해서 z번 섬에 도달 가능한지?
		// dp[x][y][z]|=dp[x][y-1][z']
		// 0번째 섬  ~ n-1번째 섬
		ll dp[n][500+1][n];
		for(ll i=0;i<n;++i){
			for(ll j=0;j<500+1;++j){
				for(ll k=0;k<n;++k){
					dp[i][j][k]=0;
				}
			}
		}
		for(ll i=0;i<n;++i){
			dp[i][0][i]=1;
		}
		for(ll i=0;i<n;++i){
			for(ll j=1;j<=500;++j){
				for(ll k=0;k<n;++k){
					// dp[i][j][k]=dp[i][j-1][k']
					for(ll p=0;p<g[k].size();++p){
						ll pre_num=g[k][p];
						dp[i][j][k]|=dp[i][j-1][pre_num];
					}
				}
			}
		}
		
		ll T;
		cin>>T;
		while(T--){
			ll A,K;
			cin>>A>>K;
			--A;
			ll ans=2023101800;
			for(ll i=0;i<n;++i){
				if(dp[A][K][i]){
					ans=min(ans,v[i]);
				}
			}
			if(ans==2023101800){
				cout<<-1<<"\n";
				continue;
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}