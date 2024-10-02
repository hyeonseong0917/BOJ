#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		ll a,b,c;
		ll x,y,z;
		cin>>a>>b>>c;
		cin>>x>>y>>z;
		vector<pair<ll,ll>> v;
		v.push_back({a,x});
		v.push_back({b,y});
		v.push_back({c,z});
		ll ans=0;
		for(ll i=0;i<3;++i){
			if(v[i].first>=v[i].second){
				ans+=v[i].second;
				v[i].first-=v[i].second;
				v[i].second=0;
			}else{
				ans+=v[i].first;
				v[i].second-=v[i].first;
				v[i].first=0;
			}
		}
		if(v[0].second){
			ans+=min(v[1].first,v[0].second/3);
			v[0].second-=min(v[1].first,v[0].second/3)*3;
			ans+=min(v[2].first,v[0].second/9);
			v[0].second-=min(v[2].first,v[0].second/9)*9;
		}
		if(v[1].second){
			ans+=min(v[2].first,v[1].second/3);
			v[1].second-=min(v[2].first,v[1].second/3)*3;
			ans+=min(v[0].first,v[1].second/9);
			v[1].second-=min(v[0].first,v[1].second/9)*9;
		}
		if(v[2].second){
			ans+=min(v[0].first,v[2].second/3);
			v[2].second-=min(v[0].first,v[2].second/3)*3;
			ans+=min(v[1].first,v[2].second/9);
			v[2].second-=min(v[1].first,v[2].second/9)*9;
		}
		cout<<ans;
	}
	return 0;
}