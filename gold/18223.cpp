#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
using namespace std;

#define ll long long

vector<pair<ll,ll>> v[5000+1];
vector<ll> dist(5000+1,2023101800);
ll V,E,P;
ll dijkstra(ll cur_start, ll cur_finish){
	ll ans=0;
	for(ll i=1;i<=V;++i){
		dist[i]=2023101800;
	}
	dist[cur_start]=0;
	priority_queue<pair<ll,ll>> pq;
	pq.push({0,cur_start});
	while(!pq.empty()){
		ll cur_dist=pq.top().first*-1;
		ll cur_pos=pq.top().second;
		pq.pop();
		for(ll i=0;i<v[cur_pos].size();++i){
			ll next_pos=v[cur_pos][i].first;
			ll next_dist=v[cur_pos][i].second;
			if(cur_dist+next_dist<dist[next_pos]){
				dist[next_pos]=cur_dist+next_dist;
				pq.push({dist[next_pos]*-1,next_pos});
			}
		}
	}
	return dist[cur_finish];
}

int main() {
	// your code goes here
	int t=1;
	while(t--){
		
		cin>>V>>E>>P;
		for(ll i=0;i<E;++i){
			ll a,b,c;
			cin>>a>>b>>c;
			v[a].push_back({b,c});
			v[b].push_back({a,c});
		}
		// 1에서 v까지 거리 == 1에서 p까지 거리 + p에서 v까지 거리
		ll fst_dist=dijkstra(1,V);
		ll sed_dist=dijkstra(1,P);
		ll trd_dist=dijkstra(P,V);
		if(fst_dist==sed_dist+trd_dist){
			cout<<"SAVE HIM";
		}else{
			cout<<"GOOD BYE";
		}
	}

	return 0;
}