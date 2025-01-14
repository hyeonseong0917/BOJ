#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

#define ll long long


ll dp[10000+1][500+5];

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n,m;
		cin>>n>>m;
		map<ll,ll> check;
		for(ll i=0;i<m;++i){
			ll a;
			cin>>a;
			++check[a];
		}
		for(ll i=2;i<=n;++i){
			for(ll j=0;j<=500+4;++j){
				dp[i][j]=2023101800;
			}
		}
		if(!check[2]){
			dp[2][1]=1;
		}
		for(ll i=3;i<=n;++i){
			if(check[i]) continue;
			for(ll j=1;j<=min(i-2,(ll)500);++j){
				dp[i][j]=min(dp[i-j][j],min(dp[i-j][j-1],dp[i-j][j+1]))+1;
			}
		}
		ll ans=2023101800;
		for(ll i=1;i<=500;++i){
			ans=min(ans,dp[n][i]);
			// cout<<i<<" "<<dp[n][i]<<endl;
		}
		if(ans>=2023101800){
			cout<<-1;
		}else{
			cout<<ans;
		}
	}
	return 0;
}