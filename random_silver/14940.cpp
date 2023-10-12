#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

#define ll long long

int n,m;
const int MAX=1000+1;
int board[MAX][MAX];
int dist[MAX][MAX];
int startY, startX;
int INF=122232421;
void Input(){
	cin>>n>>m;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			dist[i][j]=INF;
			cin>>board[i][j];
			if(board[i][j]==2){
				startY=i;
				startX=j;
				dist[i][j]=0;
			}
		}
	}
}

// 사랑해 내전부
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
bool isRange(int y ,int x){
	return (y>=0 && x>=0 && y<n &&x<m);
}
void bfs(){
	queue<pair<int,int>> q;
	q.push({startY,startX});
	dist[startY][startX]=0;
	while(!q.empty()){
		int y=q.front().first;
		int x=q.front().second;
		q.pop();
		for(int i=0;i<4;++i){
			int ny=y+dy[i];
			int nx=x+dx[i];
			if(!isRange(ny,nx)) continue;
			if(board[ny][nx]==0) continue;
			if(dist[ny][nx]>dist[y][x]+1){
				dist[ny][nx]=dist[y][x]+1;
				q.push({ny,nx});
			}
		}
	}
}

void solve(){
	bfs();
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(board[i][j]==0){
				cout<<0<<" ";
			}else{
				if(dist[i][j]==122232421){
					cout<<-1<<" ";
				}else{
					cout<<dist[i][j]<<" ";		
				}
				
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