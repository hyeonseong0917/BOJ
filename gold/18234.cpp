#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
using namespace std;

#define ll long long

bool comp(pair<ll,ll> a, pair<ll,ll> b){
	return a.second>b.second;
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n,t;
		cin>>n>>t;
		vector<pair<ll,ll>> v;
		for(ll i=0;i<n;++i){
			ll a,b;
			cin>>a>>b;
			v.push_back({a,b});
		}
		sort(v.begin(),v.end(),comp);
		ll ans=0;
		ll cnt=0;
		for(ll i=n-1;i>=0;--i){
			ans+=v[i].first+v[i].second*(t-n+cnt);
			// cout<<ans<<endl;
			++cnt;
		}
		cout<<ans;
	}
	return 0;
}