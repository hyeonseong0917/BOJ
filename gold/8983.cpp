#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll m,n,l;
		cin>>m>>n>>l;
		vector<ll> v(m,0);
		for(ll i=0;i<m;++i){
			cin>>v[i];
		}
		vector<pair<ll,ll>> p;
		for(ll i=0;i<n;++i){
			ll a,b;
			cin>>a>>b;
			p.push_back({a,b});
		}
		sort(v.begin(),v.end());
		ll ans=0;
		for(ll i=0;i<n;++i){
			ll x=p[i].first;
			ll y=p[i].second;
			ll L=0, R=m-1;
			ll bigger_x=2023101800;
			while(L<=R){
				ll mid=(L+R)/2;
				if(v[mid]>=x){
					bigger_x=min(bigger_x,v[mid]);
					R=mid-1;
				}else{
					// v[mid]<x
					L=mid+1;
				}
			}
			ll smaller_x=-1;
			L=0, R=m-1;
			while(L<=R){
				ll mid=(L+R)/2;
				if(v[mid]<=x){
					smaller_x=max(smaller_x,v[mid]);
					L=mid+1;
				}else{
					R=mid-1;
				}
			}
			if(bigger_x==2023101800){
				ll dist=abs(x-smaller_x)+y;
				if(dist<=l){
					++ans;
				}
				continue;
			}
			if(smaller_x==-1){
				ll dist=abs(x-bigger_x)+y;
				if(dist<=l){
					++ans;
				}
				continue;
			}
			ll dist=min(abs(x-bigger_x)+y,abs(x-smaller_x)+y);
			if(dist<=l){
				++ans;
			}

		}
		cout<<ans;
	}
	return 0;
}