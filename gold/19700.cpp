#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

#define ll long long
#define pb push_back

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		ll n;
		cin>>n;
		vector<pair<ll,ll>> p;
		for(ll i=0;i<n;++i){
			ll a,b;
			cin>>a>>b;
			p.pb({a,b});
		}
		sort(p.begin(),p.end());
		vector<ll> v;
		v.push_back(1);
		for(ll i=n-2;i>=0;--i){
			ll cur_num=p[i].second-1;
			// cur_num보다 작거나 같은 최소의 인덱스를 구한다
			ll L=0, R=v.size()-1;
			ll min_idx=2023101800;
			while(L<=R){
				ll mid=(L+R)/2;
				if(v[mid]<=cur_num){
					min_idx=min(min_idx,mid);
					R=mid-1;
				}else{
					L=mid+1;
				}
			}
			if(min_idx==2023101800){
				v.push_back(1);
			}else{
				++v[min_idx];
			}
		}
		ll ans=v.size();
		cout<<ans;
	}
		

	return 0;
}