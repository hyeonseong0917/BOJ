#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX=50000+1;
int N,M;
vector<pair<int,int>> g[MAX];
priority_queue<pair<int,int>> pq;
int dist[MAX];
void Input(){
	cin>>N>>M;
	for(int i=0;i<M;++i){
		int a,b,c;
		cin>>a>>b>>c;
		g[a].push_back({b,c});
		g[b].push_back({a,c});
	}
	for(int i=0;i<MAX;++i){
		dist[i]=122232421;
	}
}
void dijkstra(int start){
	pq.push({0,start}); 
	dist[start]=0;
	while(!pq.empty()){
		int cur_dist=pq.top().first*-1;
		int cur_pos=pq.top().second;
		// cout<<cur_pos<<" "<<cur_dist<<endl;
		pq.pop();
		for(int i=0;i<g[cur_pos].size();++i){
			int next_pos=g[cur_pos][i].first;
			int next_dist=g[cur_pos][i].second;
			if(dist[cur_pos]+next_dist<dist[next_pos]){
				dist[next_pos]=dist[cur_pos]+next_dist;
				pq.push({dist[next_pos]*-1,next_pos});
			}
		}
	}
}
void solve(){
	dijkstra(1);
	cout<<dist[N];
}


int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}