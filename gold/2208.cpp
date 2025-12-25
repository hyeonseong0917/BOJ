#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long



int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n,m;
		cin>>n>>m;
		vector<ll> v(n,0);
		vector<ll> dp(n,0);
		vector<ll> psum(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		psum[0]=v[0];
		for(ll i=1;i<n;++i){
			psum[i]=psum[i-1]+v[i];
		}
		dp[0]=min(0ll,psum[0]);
		for(ll i=1;i<n;++i){
			dp[i]=min(dp[i-1],psum[i]);
		}
		ll ans=max(0ll,psum[m-1]);
		for(ll i=m;i<n;++i){
			ans=max(ans,psum[i]-dp[i-m]);
		}
		cout<<ans;
	}
	return 0;
}