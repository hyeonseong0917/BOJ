#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

#define ll long long

int N,M;
const int MAX=50+1;
string board[MAX];
vector<pair<int,int>> v;
pair<int,int> start, finish;
int vs;
void Input(){
	cin>>M>>N;
	for(int i=0;i<N;++i){
		cin>>board[i];
		for(int j=0;j<M;++j){
			if(board[i][j]=='X'){
				v.push_back({i,j});
			}
			if(board[i][j]=='S'){
				start.first=i;
				start.second=j;
			}
			if(board[i][j]=='E'){
				finish.first=i;
				finish.second=j;
			}
		}
	}
	vs=v.size();
}
vector<int> picked;
int res=122232421;
int INF=122232421;
bool visited[5+1];
int dist[MAX][MAX];
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<N && x<M);
}
int dijkstra(int sy, int sx, int fy, int fx){
	dist[sy][sx]=0;
	priority_queue<pair<int,pair<int,int>>> pq;
	pq.push({0,{sy,sx}});
	while(!pq.empty()){
		int cur_dist=pq.top().first*-1;
		int y=pq.top().second.first;
		int x=pq.top().second.second;
		if(y==fy && x==fx){
			return cur_dist;
		}
		pq.pop();
		for(int i=0;i<4;++i){
			int ny=y+dy[i];
			int nx=x+dx[i];
			if(!isRange(ny,nx)) continue;
			if(board[ny][nx]=='#') continue;
			int next_dist=cur_dist+1;
			if(dist[ny][nx]>next_dist){
				dist[ny][nx]=next_dist;
				pq.push({next_dist*-1,{ny,nx}});
			}
		}
	}
	return -1;
}
int calc_dist(){
	vector<pair<int,int>> pos;
	pos.push_back({start.first, start.second});
	for(int i=0;i<v.size();++i){
		pos.push_back(v[picked[i]]);
	}
	pos.push_back({finish.first, finish.second});
	int cur_dist=0;
	for(int i=0;i<pos.size()-1;++i){
		int sy=pos[i].first;
		int sx=pos[i].second;

		int fy=pos[i+1].first;
		int fx=pos[i+1].second;
		for(int j=0;j<N;++j){
			for(int k=0;k<M;++k){
				dist[j][k]=INF;
			}
		}
		cur_dist+=dijkstra(sy,sx,fy,fx);
	}
	return cur_dist;
}
void pick(){
	if(picked.size()==v.size()){
		int cur_num=calc_dist();
		// cout<<cur_num<<endl;
		res=min(res,cur_num);
		return;
	}
	for(int i=0;i<v.size();++i){
		if(!visited[i]){
			visited[i]=1;
			picked.push_back(i);
			pick();
			picked.pop_back();
			visited[i]=0;
		}
	}
}
void solve(){
	pick();
	cout<<res;
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