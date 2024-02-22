#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

int N,M;
const int MAX=10+1;
int board[MAX][MAX];
int dist[MAX][MAX];
bool visited[MAX][MAX][4];
int INF=122232421;
vector<pair<int,int>> pos;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<N && x<N);
}
void Input(){
	cin>>N>>M;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin>>board[i][j];
		}
	}
}
int dijkstra(){
	priority_queue<pair<int,pair<int,pair<int,int>>>> pq;
	pq.push({0,{0,{0,0}}});
	dist[0][0]=0;
	while(!pq.empty()){
		int cur_time=pq.top().first*-1;
		int flag=pq.top().second.first;
		int y=pq.top().second.second.first;
		int x=pq.top().second.second.second;
		// cout<<y<<" "<<x<<" "<<cur_time<<endl;
		if(y==N-1 && x==N-1){
			return cur_time;
		}
		pq.pop();
		for(int i=0;i<4;++i){
			int ny=y+dy[i];
			int nx=x+dx[i];
			if(!isRange(ny,nx)) continue;
			if(board[ny][nx]==0) continue;
			if(board[ny][nx]==1){
				if(dist[ny][nx]>cur_time+1){
					dist[ny][nx]=cur_time+1;
					pq.push({(cur_time+1)*-1, {0,{ny,nx}}});	
				}
			}else if(flag==0){
				int new_time=cur_time+1;
				while((new_time%board[ny][nx])!=0){
					++new_time;
				}
				if(dist[ny][nx]>new_time){
					pq.push({new_time*-1, {1,{ny,nx}}});
					dist[ny][nx]=new_time;
				}
				
			}
		}
	}
	return -1;
}
void dfs(int y, int x, int dir){
	int ny=y+dy[dir];
	int nx=x+dx[dir];
	if(!isRange(ny,nx)) return;
	if(visited[ny][nx][dir]) return;
	if(board[ny][nx]!=0) return;
	visited[ny][nx][dir]=1;
	dfs(ny,nx,dir);
}
void solve(){
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			if(board[i][j]==0){
				for(int k=0;k<4;++k){
					dfs(i,j,k);
				}
			}
		}
	}
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			if(board[i][j]==0){
				if((visited[i][j][1] || visited[i][j][3]) && (visited[i][j][0] || visited[i][j][2])){
					continue;	
				}
				pos.push_back({i,j});
			}
		}
	}
	int ans=INF;
	for(int i=0;i<pos.size();++i){
		int y=pos[i].first;
		int x=pos[i].second;
		// cout<<y<<" "<<x<<endl;
		board[y][x]=M;
		for(int k=0;k<N;++k){
			for(int p=0;p<N;++p){
				dist[k][p]=INF;
			}
		}
		int res=dijkstra();
		if(res!=-1){
			ans=min(ans,res);
		}
		board[y][x]=0;
	}
	cout<<ans;
	
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);	
	Input();
	solve();
	return 0;
}