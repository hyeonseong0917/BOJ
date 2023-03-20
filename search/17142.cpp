#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N=0,M=0;
const int MAX=50+1;
int board[MAX][MAX]={0,};
int tmp[MAX][MAX]={0,};
int dist[MAX][MAX]={0,};
vector<pair<int,int>> p;
queue<int> firstZero;
queue<int> zero;
void Input(){
	cin>>N>>M;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin>>board[i][j];
			if(board[i][j]==2){
				p.push_back({i,j});
			}
			if(board[i][j]==0){
				firstZero.push(0);
			}
		}
	}
}
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<N && x<N);
}
vector<bool> visited(MAX,0);
vector<int> v;

int minNum=122232421;
int bfs(){
	if(zero.empty()){
		return 0;
	}
	int res=0;
	queue<pair<int,int>> q;
	bool check[MAX][MAX]={0,};
	
	for(int i=0;i<v.size();++i){
		q.push(p[v[i]]);
		dist[p[v[i]].first][p[v[i]].second]=0;
	}
	int cnt=0;
	bool flag=0;
	while(!q.empty()){
		int y=q.front().first;
		int x=q.front().second;
		q.pop();
		for(int i=0;i<4;++i){
			int ny=y+dy[i];
			int nx=x+dx[i];
			if(isRange(ny,nx) && board[ny][nx]!=1 && dist[ny][nx]==-1){
				dist[ny][nx]=dist[y][x]+1;
				if(board[ny][nx]==0){
					++cnt;
					res=max(res,dist[ny][nx]);
				}
				q.push({ny,nx});
				
			}
		}
	}
	if(cnt!=zero.size()){
		res=122232421;
	}

	return res;
}
void dfs(int idx, int cnt){
	if(idx==p.size() || cnt==M){
		if(cnt==M){
			for(int i=0;i<N;++i){
				for(int j=0;j<N;++j){
					tmp[i][j]=board[i][j];
				}
			}
			// bfs();
			zero=firstZero;
			memset(dist,-1,sizeof(dist));
			minNum=min(minNum,bfs());
			for(int i=0;i<N;++i){
				for(int j=0;j<N;++j){
					board[i][j]=tmp[i][j];
				}
			}
			// cout<<bfs()<<endl;
			// cout<<bfs()<<endl;
			// for(int i=0;i<M;++i){
			// 	cout<<v[i]<<" ";
			// }cout<<endl;	
		}
		
		return;
	}
	for(int i=idx;i<p.size();++i){
		if(!visited[i]){
			visited[i]=1;
			v.push_back(i);
			dfs(i+1,cnt+1);
			visited[i]=0;
			v.pop_back();
		}
	}
}
int main() {
	// your code goes here
	Input();
	dfs(0,0);
	if(minNum==122232421){
		cout<<-1;
	}else{
		cout<<minNum;	
	}
	
	return 0;
}