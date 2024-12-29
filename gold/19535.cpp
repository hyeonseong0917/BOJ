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
	ll o=1;
	while(o--){
		vector<pair<ll,ll>> v;
		ll n;
		cin>>n;
		vector<ll> g[n+1];
		for(ll i=0;i<n-1;++i){
			ll a,b;
			cin>>a>>b;
			v.push_back({a,b});
			g[a].push_back(b);
			g[b].push_back(a);
		}
		ll d_num=0, g_num=0;

		for(ll i=1;i<=n;++i){
			if(g[i].size()>=3){
				ll gs=g[i].size();
				g_num+=(gs*(gs-1)*(gs-2))/6;
			}
		}
		for(ll i=0;i<n-1;++i){
			ll a=v[i].first;
			ll b=v[i].second;
			ll as=g[a].size();
			ll bs=g[b].size();
			as-=1;
			bs-=1;
			d_num+=(as*bs);
		}
		// cout<<d_num<<endl;
		if(d_num>g_num*3){
			cout<<"D";
		}else if(d_num<g_num*3){
			cout<<"G";
		}else{
			cout<<"DUDUDUNGA";
		}
	}
	return 0;
}