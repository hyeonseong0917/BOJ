#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define ll long long

int main() {
	// your code goes here
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
		vector<pair<ll,ll>> p;
		ll L=0, R=v[0].second;
		for(ll i=1;i<n;++i){
			if(v[i].first<=R){
				R=max(v[i].second,R);
			}else{
				p.push_back({L,R});
				L=v[i].first;
				R=v[i].second;
			}
		}
		p.push_back({L,R});
		sort(p.begin(),p.end());
		ll x=0, y=p[0].second, z=y+y-x;
		ll idx=0;
		for(ll i=1;i<p.size();++i){
			if(p[i].first<=z){
				idx=i;
				z=max(z,p[i].second+p[i].second-p[i].first);
			}
		}
		cout<<p[idx].second;
	}
	return 0;
}