#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define ll long long

ll n,m;
char school_type[1000+1];
vector<pair<ll,pair<ll,ll>>> v;
vector<ll> parent(1000+1,0);

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
		for(ll i=0;i<n;++i){
			cin>>school_type[i];
			parent[i]=i;
		}
		for(ll i=0;i<m;++i){
			ll a,b,c;
			cin>>a>>b>>c;
			--a;
			--b;
			if(school_type[a]==school_type[b]) continue;
			v.push_back({c,{a,b}});
		}
		sort(v.begin(),v.end());
		ll cnt=0;
		ll ans=0;
		for(ll i=0;i<v.size();++i){
			ll cur_dist=v[i].first;
			ll cur_from=v[i].second.first;
			ll cur_to=v[i].second.second;
			// cout<<cur_dist<<" "<<cur_from<<" "<<cur_to<<endl;
			if(FIND(cur_from)==FIND(cur_to)) continue;
			UNION(cur_from,cur_to);
			++cnt;
			ans+=cur_dist;
		}
		if(cnt==n-1){
			cout<<ans;
		}else{
			cout<<-1;
		}
	}
	return 0;
}