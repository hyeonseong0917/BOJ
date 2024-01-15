#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N,M;
vector<pair<int,int>> g[1000+1];
vector<pair<int,int>> v;
void Input(){
	cin>>N>>M;
	for(int i=0;i<N-1;++i){
		int a,b,c;
		cin>>a>>b>>c;
		g[a].push_back({b,c});
		g[b].push_back({a,c});
		
	}
	for(int i=0;i<M;++i){
		int a,b;
		cin>>a>>b;
		v.push_back({a,b});
	}
}
int dist[1000+1];
void Init(){
	for(int i=1;i<=N;++i){
		dist[i]=122232421;
	}
}
void dijkstra(int start_node, int last_node){
	priority_queue<pair<int,int>> pq;
	pq.push({0,start_node});
	dist[start_node]=0;
	while(!pq.empty()){
		int cur_dist=pq.top().first*-1;
		int cur_node=pq.top().second;
		if(cur_node==last_node){
			break;
		}
		pq.pop();
		for(int i=0;i<g[cur_node].size();++i){
			int next_node=g[cur_node][i].first;
			int next_dist=g[cur_node][i].second;
			// cout<<start_node<<" "<<next_node<<endl;
			if(dist[next_node]>cur_dist+next_dist){
				dist[next_node]=cur_dist+next_dist;
				pq.push({dist[next_node]*-1,next_node});
			}
		}
	}
}
void solve(){
	// Init();
	// dijkstra(3,2);
	// cout<<dist[2];
	for(int i=0;i<v.size();++i){
		int fst_node=v[i].first;
		int sed_node=v[i].second;
		Init();
		dijkstra(fst_node,sed_node);
		cout<<dist[sed_node]<<"\n";
	}
}


int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}