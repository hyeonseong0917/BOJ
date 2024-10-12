#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		ll n;
		cin>>n;
		vector<pair<ll,ll>> v;
		for(ll i=0;i<n;++i){
			ll a,b;
			cin>>a>>b;
			v.push_back({a,b});
		}
		sort(v.begin(),v.end());
		ll cnt=0;
		cnt+=v[0].first+v[0].second;
		for(ll i=1;i<n;++i){
			cnt=max(cnt,v[i].first);
			cnt+=v[i].second;
		}
		cout<<cnt;
	}
	return 0;
}