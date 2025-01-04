#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

#define ll long long

// dp[x][y]: x번째 idx까지 봤고, 마지막 인덱스가 y일때? 했을 때 현재 높이
// 현재 x번째 인덱스를 가져가는건 어떻게 표현해야됨????

ll dp[100+1];
bool comp(pair<ll,ll> a,pair<ll,ll> b){
	if(a.first==b.first){
		return a.second<b.second;
	}
	return a.first<b.first;
}
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n;
		cin>>n;
		vector<pair<ll,ll>> v;
		for(ll i=0;i<n;++i){
			ll a,b;
			cin>>a>>b;
			v.push_back({min(a,b),max(a,b)});
			dp[i]=1;
		}
		sort(v.begin(),v.end(),comp);
		for(ll i=1;i<n;++i){
			// dp[i]를 구함
			for(ll j=0;j<i;++j){
				if(v[j].first<=v[i].first && v[j].second<=v[i].second){
					dp[i]=max(dp[i],dp[j]+1);
				}
			}
		}
		ll ans=0;
		for(ll i=0;i<n;++i){
			ans=max(ans,dp[i]);
		}
		cout<<ans;
	}
	return 0;
}