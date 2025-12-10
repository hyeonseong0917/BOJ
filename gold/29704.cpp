#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n,T;
		cin>>n>>T;
		vector<pair<ll,ll>> v;
		ll sum=0;
		for(ll i=0;i<n;++i){
			ll a,b;
			cin>>a>>b;
			sum+=b;
			v.push_back({a,b});
		}
		vector<ll> dp(1000+1,0);
		// dp[x]: x번째 날짜까지 했을 때 최댓값
		for(ll i=0;i<n;++i){
			ll cur_cost=v[i].first;
			ll cur_val=v[i].second;
			for(ll j=T;j>=0;--j){
				if(j+cur_cost>T){
					continue;
				}
				dp[j+cur_cost]=max(dp[j+cur_cost],dp[j]+cur_val);
				// cout<<i<<" "<<j<<" "<<j+cur_cost<<" "<<dp[j+cur_cost]<<"\n";
			}
		}
		ll max_num=0;
		for(ll i=1;i<=T;++i){
			// cout<<i<<" "<<dp[i]<<endl;
			max_num=max(max_num,dp[i]);
		}
		cout<<sum-max_num<<"\n";
	}
	return 0;
}