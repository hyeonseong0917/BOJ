#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define ll long long

bool comp(pair<ll,ll> a, pair<ll,ll> b){
	if(a.second==b.second){
		return a.first<b.first;
	} 
	return a.second<b.second;
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t;
	cin>>t;
	while(t--){
		ll n,m;
		cin>>n>>m;
		vector<pair<ll,ll>> v;
		for(ll i=0;i<m;++i){
			ll a,b;
			cin>>a>>b;
			v.push_back({a,b});
		}
		sort(v.begin(),v.end(),comp);
		vector<bool> check(n+1,0);
		ll ans=0;
		for(ll i=0;i<m;++i){
			ll a=v[i].first;
			ll b=v[i].second;
			for(ll j=a;j<=b;++j){
				if(!check[j]){
					check[j]=1;
					++ans;
					break;
				}
			}
		}
		cout<<ans<<"\n";

	}
	return 0;
}