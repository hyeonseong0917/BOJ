#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define ll long long

const ll MAX=5000+1;
vector<pair<ll,ll>> v[MAX];
ll dist[MAX];
ll INF=2023101800;

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n,m;
		cin>>n>>m;
		for(ll i=0;i<m;++i){
			ll a,b,c;
			cin>>a>>b>>c;
			v[a].push_back({b,c});
			v[b].push_back({a,c});
			// a와 b는 c의 가중치로 이어짐
		}
		for(ll i=0;i<MAX;++i){
			dist[i]=INF;
		}
		ll a,b;
		cin>>a>>b;
		dist[a]=0;
		priority_queue<pair<ll,ll>> pq;
		pq.push({0,a});
		while(!pq.empty()){
			ll cur_dist=pq.top().first*-1;
			ll cur_num=pq.top().second;
			pq.pop();
			for(ll i=0;i<v[cur_num].size();++i){
				ll next_dist=v[cur_num][i].second;
				ll next_num=v[cur_num][i].first;
				if(cur_dist+next_dist<dist[next_num]){
					dist[next_num]=cur_dist+next_dist;
					pq.push({dist[next_num]*-1,next_num});
				}
			}
		}
        cout<<dist[b];
	}
	return 0;
}