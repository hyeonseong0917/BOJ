#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// cin>>o;
	while(o--){
		ll n,m;
		cin>>n>>m;
		vector<ll> v(m,0);
		for(ll i=0;i<m;++i){
			cin>>v[i];
		}
		vector<ll> p;
		vector<ll> check(n+1,0);
		for(ll i=0;i<m;++i){
			p.push_back(v[i]);
			for(ll j=i+1;j<m;++j){
				if(v[i]+v[j]>n) continue;
				if(check[v[i]+v[j]]) continue;
				++check[v[i]+v[j]];
				p.push_back(v[i]+v[j]);
			}
		}
		ll INF=2023101800;
		vector<ll> dp(n+1,INF);
		dp[0]=0;
		for(ll i=0;i<=n;++i){
			for(ll j=0;j<p.size();++j){
				if(i-p[j]<0) continue;
				dp[i]=min(dp[i],dp[i-p[j]]+1);
			}
		}
		ll ans=dp[n];
		if(ans==INF){
			ans=-1;
		}
		cout<<ans;
	}
	return 0;
}
