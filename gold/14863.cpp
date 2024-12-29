#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n,k;
		cin>>n>>k;
		ll dp[n+1][2][k+1];
		for(ll i=0;i<n;++i){
			for(ll j=0;j<2;++j){
				for(ll t=0;t<=k;++t){
					dp[i][j][t]=-1;
				}
			}
		}
		vector<pair<pair<ll,ll>,pair<ll,ll>>> v;
		for(ll i=0;i<n;++i){
			ll a,b,c,d;
			cin>>a>>b>>c>>d;
			v.push_back({{a,b},{c,d}});
		}
		for(ll i=v[0].first.first;i<=k;++i){
			dp[0][0][i]=v[0].first.second;
		}
		for(ll i=v[0].second.first;i<=k;++i){
			dp[0][1][i]=v[0].second.second;
		}
		ll ans=0;
		for(ll i=1;i<n;++i){
			for(ll j=v[i].first.first;j<=k;++j){
				if(dp[i-1][0][j-v[i].first.first]!=-1){
					dp[i][0][j]=dp[i-1][0][j-v[i].first.first]+v[i].first.second;
				}
				if(dp[i-1][1][j-v[i].first.first]!=-1){
					dp[i][0][j]=max(dp[i][0][j],dp[i-1][1][j-v[i].first.first]+v[i].first.second);
				}
			}
			for(ll j=v[i].second.first;j<=k;++j){
				if(dp[i-1][0][j-v[i].second.first]!=-1){
					dp[i][1][j]=dp[i-1][0][j-v[i].second.first]+v[i].second.second;
				}
				if(dp[i-1][1][j-v[i].second.first]!=-1){
					dp[i][1][j]=max(dp[i][1][j],dp[i-1][1][j-v[i].second.first]+v[i].second.second);
				}
			}
			// for(ll j=v[i].second.first;j<=k;++j){
			// 	dp[i][1][j]=max(dp[i-1][0][j-v[i].second.first],dp[i-1][1][j-v[i].second.first])+v[i].second.second;
			// }
		}
		for(ll i=1;i<=k;++i){
			ans=max(ans,max(dp[n-1][0][i],dp[n-1][1][i]));
		}
		cout<<ans;
	}
	return 0;
}