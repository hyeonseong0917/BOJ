#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
#include <unordered_map>
using namespace std;

#define ll long long

ll n,m;
vector<vector<pair<ll,ll>>> v;
vector<ll> dist(n+1,2023101800);
void dijkstra(ll start_num){
	priority_queue<pair<ll,ll>> pq;
	pq.push({0,start_num});
	dist[start_num]=0;
	while(!pq.empty()){
		ll cur_dist=pq.top().first*-1;
		ll cur_num=pq.top().second;
		pq.pop();
		for(ll i=0;i<v[cur_num].size();++i){
			ll next_num=v[cur_num][i].first;
			ll next_dist=v[cur_num][i].second;
			if(dist[next_num]>cur_dist+next_dist){
				dist[next_num]=cur_dist+next_dist;
				pq.push({dist[next_num]*-1,next_num});
			}
		}
	}
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	cin>>o;
	while(o--){
		cin>>n>>m;
		v.clear();
		for(ll i=0;i<=n;++i){
			vector<pair<ll,ll>> tmp;
			v.push_back(tmp);
		}
		for(ll i=0;i<m;++i){
			ll a,b,c;
			cin>>a>>b>>c;
			v[a].push_back({b,c});
			v[b].push_back({a,c});
		}
		ll k;
		cin>>k;
		vector<ll> f(k,0);
		for(ll i=0;i<k;++i){
			cin>>f[i];
		}
		ll ans=2023101800;
		ll room_num=-1;
		for(ll i=1;i<=n;++i){
			// i번째 방을 비밀기지로 한다면?
			ll sum=0;
			dist=vector<ll>(n+1,2023101800);
			dijkstra(i);
			for(ll j=0;j<k;++j){
				sum+=dist[f[j]];
			}
			if(ans>sum){
				ans=sum;
				room_num=i;
			}
		}
		cout<<room_num<<"\n";
	}
	return 0;
}