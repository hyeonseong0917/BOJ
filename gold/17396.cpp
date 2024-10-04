#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define ll long long
ll INF=2023101800000;
vector<ll> check(100000,0);
vector<ll> dist(100000,INF);
vector<pair<ll,ll>> v[100000];
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n,m;
		cin>>n>>m;
		
		
		for(ll i=0;i<n;++i){
			cin>>check[i];
		}
		
		check[n-1]=0;
		for(ll i=0;i<m;++i){
			ll a,b,c;
			cin>>a>>b>>c;
			// if(check[a] && a!=n-1) continue;
			// if(check[b] && b!=n-1) continue;
			if(check[a] || check[b]) continue;
			v[a].push_back({b,c});
			v[b].push_back({a,c});
		}
		dist[0]=0;
		priority_queue<pair<ll,ll>> pq;
		pq.push({0,0});
		while(!pq.empty()){
			ll cur_dist=pq.top().first*-1;
			ll cur_num=pq.top().second;
			pq.pop();
			if(dist[cur_num]<cur_dist) continue;
			for(ll i=0;i<v[cur_num].size();++i){
				ll next_num=v[cur_num][i].first;
				ll next_dist=v[cur_num][i].second;
				if(dist[next_num]>dist[cur_num]+next_dist){
					dist[next_num]=dist[cur_num]+next_dist;
					pq.push({dist[next_num]*-1,next_num});
				}
			}
		}
		if(dist[n-1]==INF){
			cout<<-1;
		}else{
			cout<<dist[n-1];
		}
	}
	return 0;
}