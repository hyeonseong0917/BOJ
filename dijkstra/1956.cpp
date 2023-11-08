#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long


int V,E;
const int MAX=400+1;
int INF=122232421;
vector<pair<int,int>> v[MAX];
void Input(){
	cin>>V>>E;
	for(int i=0;i<E;++i){
		int a,b,c;
		cin>>a>>b>>c;
		v[a].push_back({b,c});
	}
}
int ans=INF;
int dist[MAX][MAX];
priority_queue<pair<int,pair<int,int>>> pq;
void dijkstra(){
	for(int i=1;i<=V;++i){
		for(int j=1;j<=V;++j){
			dist[i][j]=INF;
		}
	}
	for(int i=1;i<=V;++i){
		for(int j=0;j<v[i].size();++j){
			dist[i][v[i][j].first]=v[i][j].second;
			pq.push({v[i][j].second*-1,{i,v[i][j].first}} );
		}
		
	}
	while(!pq.empty()){
		int cur_dist=pq.top().first*-1;
		int from_edge=pq.top().second.first;
		int to_edge=pq.top().second.second;
		pq.pop();
		for(int i=0;i<v[from_edge].size();++i){
			int next_edge=v[from_edge][i].first;
			int next_dist=v[from_edge][i].second;
			if(dist[from_edge][next_edge]>=cur_dist+next_dist){
				dist[from_edge][next_edge]=cur_dist+next_dist;
				pq.push({dist[from_edge][next_edge]*-1,{from_edge,next_edge}});
			}
		}
	}
}
void solve(){
	dijkstra();
	for(int i=1;i<=V;++i){
		if(dist[i][i]<ans) ans=min(ans,dist[i][i]);
	}
	cout<<ans;
	
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