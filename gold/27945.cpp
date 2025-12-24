#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long

ll n,m;
vector<pair<ll,pair<ll,ll>>> v;
vector<ll> parent(100000+1,0);
ll FIND(ll a){
	if(a==parent[a]) return a;
	return parent[a]=FIND(parent[a]);
}
void UNION(ll a, ll b){
	a=FIND(a);
	b=FIND(b);
	if(a!=b){
		parent[a]=b;
	}
}


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		cin>>n>>m;
		for(ll i=1;i<=n;++i){
			parent[i]=i;
		}
		for(ll i=0;i<m;++i){
			ll a,b,c;
			cin>>a>>b>>c;
			v.push_back({c,{a,b}});
		}
		sort(v.begin(),v.end());
		ll ans=1;
		for(ll i=0;i<n;++i){
			if(v[i].first!=i+1) break;
			ll fst_num=v[i].second.first;
			ll sed_num=v[i].second.second;
			if(FIND(fst_num)==FIND(sed_num)) break;
			UNION(fst_num,sed_num);
			++ans;
		}
		cout<<ans;
	}
	return 0;
}