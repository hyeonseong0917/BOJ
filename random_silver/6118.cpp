#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define ll long long
int N,M;
const int MAX=20000+1;
vector<int> g[MAX];
int dist[MAX];
bool visited[MAX];
void Input(){
	cin>>N>>M;
	for(int i=0;i<M;++i){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(int i=0;i<=N;++i){
		dist[i]=0;
	}
}
void BFS(){
	queue<pair<int,int>> q;
	q.push({1,0});
	dist[1]=0;
	visited[1]=0;
	while(!q.empty()){
		int cur_node=q.front().first;
		int cur_dist=q.front().second;
		dist[cur_node]=cur_dist;
		q.pop();
		for(int i=0;i<g[cur_node].size();++i){
			int next_node=g[cur_node][i];
			if(!visited[next_node]){
				visited[next_node]=1;
				q.push({next_node,cur_dist+1});
			}
		}
	}
}
void solve(){
	BFS();
	int max_dist=0;
	for(int i=2;i<=N;++i){
		max_dist=max(max_dist,dist[i]);
	}
	int cnt=0;
	int min_num=122232421;
	for(int i=2;i<=N;++i){
		if(dist[i]==max_dist){
			++cnt;
			min_num=min(min_num,i);
		}
	}
	cout<<min_num<<" "<<max_dist<<" "<<cnt;
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