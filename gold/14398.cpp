#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define ll long long

vector<pair<ll,ll>> g[100+1];
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n,m,r;
		cin>>n>>m>>r;
		vector<ll> v(n+1);
		for(ll i=1;i<=n;++i){
			cin>>v[i];
		}
		
		for(ll i=0;i<r;++i){
			ll a,b,c;
			cin>>a>>b>>c;
			g[a].push_back({b,c});
			g[b].push_back({a,c});
		}
		ll ans=0;
		vector<ll> dist(n+1,2023101800);
		for(ll i=1;i<=n;++i){
			dist=vector<ll>(n+1,2023101800);
			dist[i]=0;
			priority_queue<pair<ll,ll>> pq;
			pq.push({0,i});
			while(!pq.empty()){
				ll cur_num=pq.top().second;
				ll cur_dist=pq.top().first*-1;
				pq.pop();
				for(ll i=0;i<g[cur_num].size();++i){
					ll next_num=g[cur_num][i].first;
					ll next_dist=g[cur_num][i].second;
					if(cur_dist+next_dist>m) continue;
					if(dist[next_num]>cur_dist+next_dist){
						dist[next_num]=cur_dist+next_dist;
						pq.push({dist[next_num]*-1,next_num});
					}
				}
			}
			ll cur_sum=0;
			for(ll j=1;j<=n;++j){
				if(dist[j]==2023101800) continue;
				cur_sum+=v[j];
			}
			ans=max(ans,cur_sum);
		}
		cout<<ans;

	}
	return 0;
}