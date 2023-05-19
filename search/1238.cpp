#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N,M,X;
const int MAX=1000+1;
vector<pair<int,int>> graph[MAX];
int dist[MAX];
int ans[MAX];
void Input(){
	cin>>N>>M>>X;
	for(int i=0;i<M;++i){
		int a,b,c=0;
		cin>>a>>b>>c;
		graph[a].push_back({b,c});
	}
}
const int INF=122232421;
void dijkstra(int start){
	
	priority_queue<pair<int,int>> pq;
	pq.push({0,start});
	dist[start]=0;
	while(!pq.empty()){
		int cur_dist=pq.top().first*-1;
		int cur_pos=pq.top().second;
		pq.pop();
		for(int i=0;i<graph[cur_pos].size();++i){
			int next_pos=graph[cur_pos][i].first;
			int next_dist=graph[cur_pos][i].second;
			// cout<<next_pos<<endl;
			if(dist[next_pos]>dist[cur_pos]+next_dist){
				dist[next_pos]=dist[cur_pos]+next_dist;
				pq.push({dist[next_pos]*-1, next_pos});
			}
		}
	}
}
void solve(){
	for(int i=1;i<=N;++i){
		for(int j=0;j<MAX;++j){
			dist[j]=INF;
		}
		dijkstra(i);
		ans[i]+=dist[X];
	}
	for(int j=0;j<MAX;++j){
		dist[j]=INF;
	}
	dijkstra(X);
	for(int i=1;i<=N;++i){
		ans[i]+=dist[i];
	}
	int maxNum=-1;
	for(int i=1;i<=N;++i){
		maxNum=max(maxNum,ans[i]);
	}
	cout<<maxNum;
}

int main() {
	// your code goes here
	Input();
	solve();
	// dijkstra(X);
	// cout<<dist[1]<<" "<<dist[2]<<" "<<dist[3]<<" "<<dist[4];
	return 0;
}