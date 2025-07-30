#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

bool comp(pair<ll,ll> a, pair<ll,ll> b){
	return a.first>b.first;
}
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// cin>>o;
	while(o--){
		ll n,m,k;
		cin>>n>>m>>k;
		vector<pair<ll,ll>> v;
		for(ll i=0;i<n;++i){
			ll a,b;
			cin>>a>>b;
			v.push_back({a,b});
		}
		sort(v.begin(),v.end(),comp);
		map<ll,ll> check;
		priority_queue<pair<ll,ll>> pq;
		for(ll i=0;i<n;++i){
			if(pq.size()<k){
				pq.push({v[i].second*-1,i});
			}else{
				ll cur_num=v[i].second;
				ll top_num=pq.top().first*-1;
				if(cur_num>top_num){
					pq.pop();
					pq.push({cur_num*-1,i});
				}
			}
		}
		vector<ll> visited(n,0);
		ll ps=pq.size();
		// cout<<ps<<endl;
		while(!pq.empty()){
			ll idx=pq.top().second;
			// cout<<idx<<endl;
			pq.pop();
			++visited[idx];
		}
		ll cnt=0;
		for(ll i=0;i<n;++i){
			if(cnt==m) break;
			if(visited[i]) continue;
			++visited[i];
			++cnt;
		}
		ll ans=0;
		for(ll i=0;i<n;++i){
			if(visited[i]){
				ans+=v[i].first;
				// cout<<ans<<endl;
			}
		}
		cout<<ans;
	}	
	return 0;
}