#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define ll long long

bool comp(pair<ll,ll> a, pair<ll,ll> b){
	return a.second<b.second;
}

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
		vector<ll> tmp;
		map<ll,ll> m;
		ll d;
		for(ll i=0;i<n;++i){
			ll a,b;
			cin>>a>>b;
			ll tmp_a=a;
			ll tmp_b=b;
			a=min(tmp_a,tmp_b);
			b=max(tmp_a,tmp_b);
			if(!m[a]){
				++m[a];
				tmp.push_back(a);
			}
			v.push_back({a,b});
		}
		sort(tmp.begin(),tmp.end());
		sort(v.begin(),v.end(),comp);
		// for(ll i=0;i<n;++i){
		// 	cout<<v[i].first<<" "<<v[i].second<<"\n";
		// }
		cin>>d;
		priority_queue<pair<ll,ll>> pq;
		ll L=0;
		ll ans=0;
		for(ll i=0;i<tmp.size();++i){
			ll s=tmp[i];
			ll f=tmp[i]+d;
			while(!pq.empty()){
				ll cur_start=pq.top().first*-1;
				if(cur_start<s){
					pq.pop();
				}else{
					break;
				}
			}
			while(L<n){
				if(v[L].second<=f){
					pair<ll,ll> p=v[L];
					p.first*=-1;
					pq.push(p);
					++L;
				}else{
					break;
				}
			}
			while(!pq.empty()){
				ll cur_start=pq.top().first*-1;
				if(cur_start<s){
					pq.pop();
				}else{
					break;
				}
			}
			if(!pq.empty()){
				ll ps=pq.size();
				ans=max(ans,ps);
			}
		}
		cout<<ans;
	}
	return 0;
}