#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

#define ll long long
#define pb push_back


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=1;	
	// cin>>t;
	while(t--){	
		ll n;
		cin>>n;
		vector<pair<ll,ll>> p;
		for(ll i=0;i<n;++i){
			ll a;
			cin>>a;
			p.push_back({a,i});
		}
		sort(p.begin(),p.end());
		vector<ll> ans(n,0);
		ll cur_num=0;
		for(ll i=0;i<n;++i){
			ans[p[i].second]=cur_num++;
		}
		for(ll i=0;i<n;++i){
			cout<<ans[i]<<" ";
		}
	}
	return 0;
}