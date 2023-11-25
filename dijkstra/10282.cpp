#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

const int MAX=10000+1;
vector<pair<int,int>> v[MAX]; // v[b]={a,s}
int dist[MAX];
int n,d,c;
int INF=1222232421;
void dijkstra(int start){
	priority_queue<pair<int,int>> pq;
	pq.push({0,start});
	dist[start]=0;
	int total_time=0;
	int total_cpu=1;
	while(!pq.empty()){
		int cur_dist=pq.top().first*-1;
		int cur_pos=pq.top().second;
		pq.pop();
		for(int i=0;i<v[cur_pos].size();++i){
			int next_pos=v[cur_pos][i].first;
			int next_dist=v[cur_pos][i].second;
			if(dist[next_pos]>cur_dist+next_dist){
				dist[next_pos]=cur_dist+next_dist;
				pq.push({dist[next_pos]*-1,next_pos});
			}
		}
	}
	for(int i=1;i<=n;++i){
		if(i==start) continue;
		if(dist[i]==INF) continue;
		++total_cpu;
		total_time=max(total_time,dist[i]);
	}
	cout<<total_cpu<<" "<<total_time<<"\n";
}
void solve(){
	int t=0;
	cin>>t;
	while(t--){
		cin>>n>>d>>c;
		for(int i=1;i<=n;++i){
			v[i].clear();
			dist[i]=INF;
		}
		for(int i=0;i<d;++i){
			int a,b,s;
			cin>>a>>b>>s;
			v[b].push_back({a,s});
		}
		dijkstra(c);
	}
}


int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	solve();
	return 0;
}