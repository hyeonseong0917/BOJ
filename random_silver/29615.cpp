#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <cmath>
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
		ll n,m;
		cin>>n>>m;
		vector<ll> a(n,0);
		for(ll i=0;i<n;++i){
			cin>>a[i];
		}
		map<ll,ll> check;
		for(ll i=0;i<m;++i){
			ll b;
			cin>>b;
			++check[b];
		}
		// m번째까지 b[i]의 수들이 있어야함.
		vector<pair<ll,ll>> v;
		for(ll i=0;i<n;++i){
			if(check[a[i]]){
				v.push_back({a[i],i});
			}
		}
		// v에는 {값,인덱스}
		ll ans=0;
		for(ll i=0;i<v.size();++i){
			if(v[i].second>=m){
				++ans;
			}
		}
		cout<<ans;

	} 
	return 0;
}