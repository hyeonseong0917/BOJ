#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;

#define ll long long

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// cin>>o;
	while(o--){
		ll n,m;
		cin>>n>>m;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		ll p;
		cin>>p;
		vector<pair<ll,ll>> g[n];
		for(ll i=0;i<p;++i){
			ll a,b,c;
			cin>>a>>b>>c;
			--a;
			--b;
			v[b]+=c;
			g[a].push_back({b,c});
		}
		priority_queue<pair<ll,ll>> pq;
		for(ll i=0;i<n;++i){
			pq.push({v[i]*-1,i});
		}
		ll cnt=0;
		ll max_num=0;
		vector<ll> check(n,0);
		while(!pq.empty()){
			ll cur_num=pq.top().first*-1;
			ll cur_idx=pq.top().second;
			// cout<<cur_num<<" "<<cur_idx<<endl;
			if(check[cur_idx]){
				pq.pop();
				continue;
			}
			max_num=max(max_num,cur_num);
			pq.pop();
			++check[cur_idx];
			++cnt;
			if(cnt==m) break;
			// cout<<cur_idx<<endl;
			for(ll i=0;i<g[cur_idx].size();++i){
				ll next_idx=g[cur_idx][i].first;
				ll next_cost=g[cur_idx][i].second;
				if(check[next_idx]) continue;
				v[next_idx]-=next_cost;
				// cout<<next_idx<<" "<<v[next_idx]<<endl;
				pq.push({v[next_idx]*-1,next_idx});
			}
		}
		ll ps=pq.size();
		// cout<<ps<<endl;
		cout<<max_num;
	}
	return 0;
}