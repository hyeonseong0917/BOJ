#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
using namespace std;

#define ll long long

int N,M;
const int MAX=1000+1;
vector<pair<int,int>> v[MAX];
int dist[MAX];
bool visited[MAX][MAX];
int parent[MAX];
void Input(){
	cin>>N>>M;
	for(int i=0;i<M;++i){
		int a,b,c;
		cin>>a>>b>>c;
		v[a].push_back({b,c});
		v[b].push_back({a,c});
	}
	for(int i=0;i<=N;++i){
		dist[i]=1222232421;
	}
}
vector<int> g[MAX];

void dijkstra(int start_num){
	dist[start_num]=0;
	priority_queue<pair<int,int>> pq;
	pq.push({0,start_num});
	g[1].push_back(1);
	while(!pq.empty()){
		int cur_dist=pq.top().first*-1;
		int cur_num=pq.top().second;
		pq.pop();
		for(int i=0;i<v[cur_num].size();++i){
			int next_num=v[cur_num][i].first;
			int next_dist=v[cur_num][i].second;
			if(dist[next_num]>cur_dist+next_dist){
				parent[next_num]=cur_num;
				dist[next_num]=cur_dist+next_dist;
				pq.push({-1*dist[next_num],next_num});
				g[next_num].clear();
				for(int j=0;j<g[cur_num].size();++j){
					g[next_num].push_back(g[cur_num][j]);
				}
				g[next_num].push_back(next_num);
			}
		}
	}
}


void solve(){
	dijkstra(1);
	cout<<N-1<<"\n";
	for(int i=2;i<=N;++i){
		cout<<parent[i]<<" "<<i<<"\n";
	}
	// cout<<g[4][0]<<" "<<g[4][1]<<g[4][2];
	// int ans=0;
	// vector<pair<int,int>> p;
	// for(int i=2;i<=N;++i){
	// 	// cout<<i<<" "<<g[i].size()<<endl;
	// 	for(int j=0;j<g[i].size()-1;++j){
	// 		if(i==g[i][j]) continue;
	// 		int next_num=g[i][j];
	// 		if(!visited[g[i][j]][g[i][j+1]]){
	// 			// cout<<i<<" "<<next_num<<"\n";
	// 			visited[i][next_num]=1;
	// 			visited[next_num][i]=1;
	// 			p.push_back({g[i][j],g[i][j+1]});
	// 			++ans;
	// 		}
	// 	}
	// }
	// cout<<ans<<"\n";
	// for(int i=0;i<p.size();++i){
	// 	cout<<p[i].first<<" "<<p[i].second<<"\n";
	// }
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);	
	Input();
	solve();
	return 0;
}