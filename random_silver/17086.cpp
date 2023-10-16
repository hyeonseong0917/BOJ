#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define ll long long

int ans=0;

const int MAX=50+1;
int board[MAX][MAX];
int N,M;
int dy[8]={-1,-1,0,1,1,1,0,-1};
int dx[8]={0,1,1,1,0,-1,-1,-1};
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<N && x<M);
}
void Input(){
	cin>>N>>M;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			cin>>board[i][j];
		}
	}
}

int bfs(int cy, int cx){
	queue<pair<int,pair<int,int>>> q;
	bool check[MAX][MAX];
	for(int i=0;i<MAX;++i){
		for(int j=0;j<MAX;++j){
			check[i][j]=0;
		}
	}
	
	check[cy][cx]=1;
	q.push({0,{cy,cx}});
	bool init=1;
	while(!q.empty()){
		int y=q.front().second.first;
		int x=q.front().second.second;
		int cnt=q.front().first;
		if(board[y][x] && !init){
			return cnt;
		}
		init=0;
		q.pop();
		for(int i=0;i<8;++i){
			int ny=y+dy[i];
			int nx=x+dx[i];
			if(!isRange(ny,nx)) continue;
			if(check[ny][nx]) continue;
			check[ny][nx]=1;
			q.push({cnt+1,{ny,nx}});
		}
	}
	return 0;
}
void solve(){
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			if(board[i][j]) continue;
			int cur_num=bfs(i,j);
			ans=max(ans,cur_num);
		}
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