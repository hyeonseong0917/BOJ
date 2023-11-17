#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

int N,M;
const int MAX=100+1;
char board[MAX][MAX];
int dist[MAX][MAX]; //dist[y][x]: y,x에 도달하기까지 제거한 벽의 개수
int INF=122232421;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
void Input(){
	cin>>M>>N;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			cin>>board[i][j];
		}
	}
}
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<N && x<M);
}
void BFS(){
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			dist[i][j]=INF;
		}
	}
	priority_queue<pair<int,pair<int,int>>> q;
	q.push({0,{0,0}});
	dist[0][0]=0;
	while(!q.empty()){
		int cnt=q.top().first*-1;
		int y=q.top().second.first;
		int x=q.top().second.second;
		// cout<<y<<" "<<x<<" "<<cnt<<endl;
		if(y==N-1 && x==M-1){
			return;
		}
		// cout<<y<<" "<<x<<endl;
		q.pop();
		for(int i=0;i<4;++i){
			int ny=y+dy[i];
			int nx=x+dx[i];
			if(!isRange(ny,nx)) continue;
			if(board[ny][nx]=='0'){
				if(dist[ny][nx]>dist[y][x]){
					dist[ny][nx]=cnt;
					q.push({cnt*-1,{ny,nx}});	
				}
			}else{
				if(dist[ny][nx]>dist[y][x]+1){
					dist[ny][nx]=cnt+1;
					q.push({(cnt+1)*-1,{ny,nx}});	
				}
			}
			//1을 만났는데 뚫기 싫을 경우도 있지 않나?

		}
	}
	// return -1;
}
void solve(){
	BFS();
	cout<<dist[N-1][M-1];
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