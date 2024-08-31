#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n,c;
		cin>>c>>n;
		ll INF=1222232421;
		vector<ll> dp(2000+1,INF);
		for(ll i=0;i<n;++i){
			ll a,b;
			cin>>a>>b;
			dp[b]=min(dp[b],a);
		}
		for(ll i=1;i<=2000;++i){
			for(ll j=1;j<i;++j){
				ll q=i/j;
				if(i%j==0){
					dp[i]=min(dp[i],q*dp[j]);
				}else{
					ll m=i%j;
					dp[i]=min(dp[i],q*dp[j]+dp[m]);
				}
			}
		}
		ll ans=INF;
		for(ll i=c;i<=2000;++i){
			ans=min(ans,dp[i]);
		}
		cout<<ans;
	}
	return 0;
}