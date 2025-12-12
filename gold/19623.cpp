#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

bool comp(pair<pair<ll,ll>,ll> a, pair<pair<ll,ll>,ll> b){
	return a.first.second<b.first.second;
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		// n개의 회의와 1개의 회의실
		// 회의를 진행할 수 있는 최대 인원
		ll n;
		cin>>n;
		vector<pair<pair<ll,ll>,ll>> v;
		map<ll,ll> m;
		vector<ll> tmp;
		for(ll i=0;i<n;++i){
			ll a,b,c;
			cin>>a>>b>>c;
			v.push_back({{a,b},c});
			if(!m[a]){
				++m[a];
				tmp.push_back(a);
			}
			if(!m[b]){
				++m[b];
				tmp.push_back(b);
			}
		}
		sort(tmp.begin(),tmp.end());
		map<ll,ll> check;
		for(ll i=0;i<tmp.size();++i){
			check[tmp[i]]=i;
		}
		for(ll i=0;i<n;++i){
			v[i].first.first=check[v[i].first.first];
			v[i].first.second=check[v[i].first.second];
		}
		sort(v.begin(),v.end(),comp);
		// for(ll i=0;i<n;++i){
		// 	cout<<v[i].first.first<<" "<<v[i].first.second<<" "<<v[i].second<<"\n";
		// }
		vector<ll> dp(200000+1,0);
		dp[v[0].first.second]=v[0].second;
		for(ll i=1;i<n;++i){
			ll fst_num=v[i-1].first.second;
			ll sed_num=v[i].first.second;
			for(ll j=fst_num;j<=sed_num;++j){
				dp[j]=max(dp[j],dp[fst_num]);
			}
			dp[sed_num]=max(dp[sed_num],dp[v[i].first.first]+v[i].second);
		}
		ll ans=0;
		for(ll i=0;i<=200000;++i){
			ans=max(ans,dp[i]);
		}
		cout<<ans;
	}
	return 0;
}