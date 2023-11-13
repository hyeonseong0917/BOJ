#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long


int N,M;
const int MAX=200+1;
vector<pair<int,int>> v[MAX];
int dist[MAX];
int INF=122232421;
// 최단 경로로 이동하기 위해 가장 먼저 방문하는 지점을 찾는 방법
void Input(){
	cin>>N>>M;
	for(int i=0;i<M;++i){
		int a,b,c;
		cin>>a>>b>>c;
		v[a].push_back({b,c});
		v[b].push_back({a,c});
	}
}
// start에서 finish까지
int dijkstra(int start, int finish){
	for(int i=0;i<MAX;++i){
		dist[i]=INF;
	}
	dist[start]=0;
	priority_queue<pair<int,pair<int,int>>> pq; // {거리, {현재 위치, 첫 번째로 이동한 위치}}
	pq.push({0,{start,start}});
	bool flag=0;
	while(!pq.empty()){
		int cur_dist=pq.top().first*-1;
		int cur_pos=pq.top().second.first;
		int first_pos=pq.top().second.second;
		pq.pop();
		if(cur_pos==finish){
			return first_pos;
		}
		for(int i=0;i<v[cur_pos].size();++i){
			int next_pos=v[cur_pos][i].first;
			int next_dist=v[cur_pos][i].second;
			// cout<<next_pos<<endl;
			if(dist[next_pos]>cur_dist+next_dist){
				dist[next_pos]=cur_dist+next_dist;
				if(!flag){
					pq.push({dist[next_pos]*-1,{next_pos,next_pos}});
				}else{
					pq.push({dist[next_pos]*-1,{next_pos,first_pos}});
				}
				
			}
		}
		flag=1;
	}
	return -1;
}

void solve(){
	// cout<<dijkstra(2,1);
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			if(i==j){
				cout<<"- ";
			}else{
				cout<<dijkstra(i,j)<<" ";
			}
		}cout<<"\n";
	}
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