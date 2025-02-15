#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

#define ll long long

ll parent[100000+1];

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
		// N개의 집과 M개의 길
		// 길을 유지하는데 드는 ㅠ지비
		// 두 개의 분리된 마을로 분할
		// n,m
		// C: 유지비
		// 어떻게 2개의 마을로 분할할까??
		// n<=10만
		ll n,m;
		cin>>n>>m;
		for(ll i=1;i<=n;++i){
			parent[i]=i;
		}
		vector<pair<ll,pair<ll,ll>>> v;
		for(ll i=0;i<m;++i){
			ll a,b,c;
			cin>>a>>b>>c;
			v.push_back({c,{a,b}});
		}
		sort(v.begin(),v.end());
		ll ans=0;
		vector<ll> p;
		for(ll i=0;i<m;++i){
			ll a=v[i].second.first;
			ll b=v[i].second.second;
			ll cost=v[i].first;
			if(FIND(a)!=FIND(b)){
				UNION(a,b);
				p.push_back(cost);
			}
		}
		for(ll i=0;i<p.size()-1;++i){
			ans+=p[i];
		}
		cout<<ans;
	} 
	return 0;
}