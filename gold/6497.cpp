#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
using namespace std;

#define ll long long

ll parent[200000+1];

ll FIND(ll a){
	if(a==parent[a]) return a;
	return parent[a]=FIND(parent[a]);
}
void UNION(ll a, ll b){
	a=FIND(a);
	b=FIND(b);
	if(a==b) return;
	parent[a]=b;
}

int main() {
	// your code goes here
	int t=1;
	while(t--){
		while(1){
			ll m,n;
			cin>>m>>n;
			if(m==0 && n==0){
				break;
			}
			vector<pair<ll,pair<ll,ll>>> v;
			ll sum=0;
			for(ll i=0;i<n;++i){
				ll a,b,c;
				cin>>a>>b>>c;
				v.push_back({c,{a,b}});
				sum+=c;
			}
			sort(v.begin(),v.end());
			for(ll i=0;i<m;++i){
				parent[i]=i;
			}
			ll ans=0;
			for(ll i=0;i<n;++i){
				if(FIND(v[i].second.first)==FIND(v[i].second.second)) continue;
				ans+=v[i].first;
				UNION(v[i].second.first, v[i].second.second);
			}
			cout<<sum-ans<<"\n";
		}
	}

	return 0;
}