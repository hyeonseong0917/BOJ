#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define ll long long

ll dp[100+1][10000+1];

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n,t;
		cin>>n>>t;
		vector<pair<ll,ll>> v;
		vector<ll> psum(n,0);
		
		for(ll i=0;i<=t;++i){
			for(ll j=0;j<=n;++j){
				dp[j][i]=0;
			}
		}
		for(ll i=0;i<n;++i){
			ll a,b;
			cin>>a>>b;
			v.push_back({a,b});
		}
		sort(v.begin(),v.end());
		psum[0]=v[0].first;
		for(ll i=1;i<n;++i){
			psum[i]=psum[i-1]+v[i].first;
		}
		dp[0][v[0].first]=v[0].second;
		for(ll i=1;i<n;++i){
			for(ll j=1;j<=t;++j){
				if(dp[i-1][j]){
					dp[i][j]=max(dp[i][j],dp[i-1][j]);
				}
			}
			for(ll j=v[i-1].first+1;j<=v[i].first;++j){
				dp[i][j]=max(dp[i][j],dp[i][j-1]);
			}
			dp[i][v[i].first]=max(dp[i][v[i].first],v[i].second);
			for(ll j=v[i].first+1;j<=min(psum[i],t);++j){
				dp[i][j]=max(dp[i][j],dp[i-1][j]);
				dp[i][j]=max(dp[i][j],v[i].second+dp[i-1][j-v[i].first]);
			}
		}
		ll ans=0;
		for(ll i=1;i<=t;++i){
			for(ll j=0;j<n;++j){
				ans=max(ans,dp[j][i]);
			}
		}
		cout<<ans;
	}
	return 0;
}