#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

#define ll long long

bool comp(pair<pair<ll,ll>,pair<ll,ll>> a, pair<pair<ll,ll>,pair<ll,ll>> b){
	if(a.first.second==b.first.second){
		return a.second.second<b.second.second;
	}
	return a.first.second<b.first.second;
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n;
		cin>>n;
		vector<ll> dp(n,0);
		vector<pair<pair<ll,ll>,pair<ll,ll>>> v;
		for(ll i=1;i<=n;++i){
			ll a,b,c;
			cin>>a>>b>>c;
			v.push_back({{i,a},{b,c}});
		}
		sort(v.begin(),v.end(),comp);
		dp[0]=v[0].second.first;
		for(ll i=1;i<n;++i){
			dp[i]=v[i].second.first;
			for(ll j=0;j<i;++j){
				if(v[j].first.second<v[i].first.second && v[j].second.second<v[i].second.second){
					dp[i]=max(dp[i],dp[j]+v[i].second.first);
				}
			}
		}
		ll max_h=0;
		for(ll i=0;i<n;++i){
			max_h=max(max_h,dp[i]);
		}
		vector<ll> ans;
		for(ll i=n-1;i>=0;--i){
			if(max_h==dp[i]){
				max_h-=v[i].second.first;
				ans.push_back(v[i].first.first);
			}
		}
		reverse(ans.begin(),ans.end());
		ll as=ans.size();
		cout<<as<<"\n";
		for(ll i=0;i<as;++i){
			cout<<ans[i]<<"\n";
		}
	}
	return 0;
}