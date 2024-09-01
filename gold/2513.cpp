#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define ll long long

bool comp(pair<ll,ll> a, pair<ll,ll> b){
	return a.first<b.first;
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=1;
	while(t--){
		ll n,k,s;
		cin>>n>>k>>s;
		vector<pair<ll,ll>> v;
		for(ll i=0;i<n;++i){
			ll a,b;
			cin>>a>>b;
			v.push_back({a,b});
		}
		sort(v.begin(),v.end());
		vector<pair<ll,ll>> fst,sed;
		for(ll i=0;i<n;++i){
			if(v[i].first<s){
				fst.push_back(v[i]);
			}else{
				sed.push_back(v[i]);
			}
		}
		reverse(sed.begin(),sed.end());

		ll idx=0;
		ll dist=0;
		ll fst_size=fst.size();
		ll sed_size=sed.size();
		while(idx<fst_size){
			dist+=(s-fst[idx].first)*2;
			ll cap=0;
			while(idx<n && v[idx].first<s){
				if(cap+fst[idx].second<=k){
					cap+=fst[idx].second;
					++idx;
				}else{
					ll diff=k-cap;
					fst[idx].second-=diff;
					break;
				}
			}
		}
		idx=0;
		while(idx<sed_size){
			dist+=abs(s-sed[idx].first)*2;
			ll cap=0;
			while(idx<sed_size){
				if(cap+sed[idx].second<=k){
					cap+=sed[idx].second;
					++idx;
				}else{
					ll diff=k-cap;
					sed[idx].second-=diff;
					break;
				}
			}
		}
		cout<<dist;
	}

	return 0;
}