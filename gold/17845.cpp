#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define ll long long

ll dp[1000+1][10000+1];
vector<pair<ll,ll>> v;
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n,k;
		cin>>n>>k;
		for(ll i=0;i<k;++i){
			ll a,b;
			cin>>a>>b;
			v.push_back({a,b});
		}
		for(ll i=0;i<=1000;++i){
			for(ll j=0;j<=10000;++j){
				dp[i][j]=0;
			}
		}
		dp[0][v[0].second]=v[0].first;
		ll ans=0;
		if(n>=v[0].second){
			ans=v[0].first;
		}
		for(ll i=1;i<k;++i){
			for(ll j=1;j<=n;++j){
				if(j>=v[i].second){
					dp[i][j]=max(dp[i][j],dp[i-1][j-v[i].second]+v[i].first);
				}
				dp[i][j]=max(dp[i][j],dp[i-1][j]);
				ans=max(ans,dp[i][j]);
			}
		}
		cout<<ans;
	}
	return 0;
}