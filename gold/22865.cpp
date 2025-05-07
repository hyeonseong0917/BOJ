#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

#define ll long long

ll n;
ll A,B,C;
ll m;
vector<pair<ll,ll>> v[100000+1];
ll pos[3];
ll dist[100000+1][3];
void dijkstra(ll idx){
	ll init_pos=pos[idx];
	dist[init_pos][idx]=0;
	priority_queue<pair<ll,ll>> pq;
	pq.push({0,init_pos});
	while(!pq.empty()){
		ll cur_dist=pq.top().first*-1;
		ll cur_pos=pq.top().second;
		pq.pop();
		for(ll i=0;i<v[cur_pos].size();++i){
			ll next_pos=v[cur_pos][i].first;
			ll next_dist=v[cur_pos][i].second;
			if(dist[next_pos][idx]>cur_dist+next_dist){
				dist[next_pos][idx]=cur_dist+next_dist;
				pq.push({dist[next_pos][idx]*-1,next_pos});
			}
		}
	}
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		// n개의 땅
		// a,b,c가 있는데 여기서 가장 먼 곳에서 살고싶음
		cin>>n;
		for(ll i=0;i<=n;++i){
			for(ll j=0;j<3;++j){
				dist[i][j]=2023101800;
			}
		}
		for(ll i=0;i<3;++i){
			cin>>pos[i];
		}
		cin>>m;
		for(ll i=0;i<m;++i){
			ll a,b,c;
			cin>>a>>b>>c;
			v[a].push_back({b,c});
			v[b].push_back({a,c});
		}
		for(ll i=0;i<3;++i){
			dijkstra(i);
		}
		ll max_dist=0;
		ll ans=0;
		for(ll i=1;i<=n;++i){
			ll c=2023101800;
			for(ll j=0;j<3;++j){
				c=min(c,dist[i][j]);
			}
			if(max_dist<c){
				ans=i;
				max_dist=c;
			}
		}
		cout<<ans;
	}

	return 0;
}