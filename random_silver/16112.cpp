#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
using namespace std;

#define ll long long

bool comp(pair<ll,pair<ll,ll>> a, pair<ll,pair<ll,ll>> b){
	if(a.second.first==b.second.first){
		return a.second.second<b.second.second;
	}
	return a.second.first<b.second.first;
}

int main() {
	// your code goes here
    ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		ll n,q;
		cin>>n>>q;
		vector<pair<ll,pair<ll,ll>>> v;
		vector<pair<ll,ll>> ans;
		for(ll i=0;i<n;++i){
			ll a,b,c;
			cin>>a>>b>>c;
			v.push_back({i+1,{a,b}});
		}
		
		sort(v.begin(),v.end(),comp);
		priority_queue<pair<ll,ll>> pq;
		map<ll,ll> m;
		ll cnt=1;
		for(ll i=0;i<n;++i){
			// cout<<v[i].second.first<<" "<<v[i].second.second<<" "<<v[i].first<<endl;
			if(pq.empty()){
				pq.push({v[i].second.second,v[i].first});
				m[v[i].first]=cnt;
			}else{
				if(pq.top().first<v[i].second.first){
					pq=priority_queue<pair<ll,ll>>();
					++cnt;
				}
				pq.push({v[i].second.second,v[i].first});
				m[v[i].first]=cnt;
			}
		}
		for(ll i=0;i<q;++i){
			ll a,b;
			cin>>a>>b;
			// cout<<a<<" "<<b<<" "<<m[a]<<" "<<m[b]<<endl;
			if(m[a]==m[b]){
				cout<<1<<"\n";
			}else{
				cout<<0<<"\n";
			}
		}
	}

	return 0;
}