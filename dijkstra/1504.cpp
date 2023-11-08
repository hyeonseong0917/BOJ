#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long


const int MAX=800+1;
int N,E;
vector<pair<int,int>> v[MAX];
int dist[MAX];
int U,V;
int INF=122232421;
void Input(){
	cin>>N>>E;
	for(int i=0;i<E;++i){
		int a,b,c;
		cin>>a>>b>>c;
		v[a].push_back({b,c});
		v[b].push_back({a,c});
	}
	cin>>U>>V;
	
}

int dijkstra(int start, int fin){
	for(int i=0;i<MAX;++i){
		dist[i]=INF;
	}
	dist[start]=0;
	priority_queue<pair<int,int>> pq;
	pq.push({0,start}); //start에서 x까지의 시간
	while(!pq.empty()){
		int cur_dist=pq.top().first*-1;
		int cur_edge=pq.top().second;
		pq.pop();
		if(cur_edge==fin){
			return cur_dist;
		}
		for(int i=0;i<v[cur_edge].size();++i){
			int next_edge=v[cur_edge][i].first;
			int next_dist=v[cur_edge][i].second;
			if(dist[next_edge]>cur_dist+next_dist){
				dist[next_edge]=cur_dist+next_dist;
				pq.push({dist[next_edge]*-1,next_edge});
			}
		}
	}
	return -1;
}
int get_fst_num(){
	if(dijkstra(1,U)==-1){
		return -1;
	}
	if(dijkstra(U,V)==-1){
		return -1;
	}
	if(dijkstra(V,N)==-1){
		return -1;
	}
	return dijkstra(1,U)+dijkstra(U,V)+dijkstra(V,N);
}
int get_sed_num(){
	if(dijkstra(1,V)==-1){
		return -1;
	}
	if(dijkstra(V,U)==-1){
		return -1;
	}
	if(dijkstra(U,N)==-1){
		return -1;
	}
	return dijkstra(1,V)+dijkstra(V,U)+dijkstra(U,N);
}
void solve(){
	// 1->u->v->N
	// 1->v->u->N
	cout<<min(get_fst_num(),get_sed_num());
}



int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	Input();
	solve();
	return 0;
}