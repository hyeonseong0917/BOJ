#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX=1000+1;
// int board[MAX][MAX];
string board[MAX];
bool visited[MAX][MAX][10+1][2+1];
int ans=122232421;
int N,M,K=0;
int dy[4+1]={-1,0,1,0};
int dx[4+1]={0,1,0,-1};
void Input(){
	
	cin>>N>>M>>K;
	for(int i=0;i<N;++i){
		cin>>board[i];
	}
}
bool isRange(int y,int x){
	return (y>=0 && x>=0 && y<N && x<M);
}
int BFS(int curY, int curX, int curK){
	// queue<pair<pair<pair<int,int>,pair<int,int>>,int>> q;
	queue<pair<pair<int,int>,pair<pair<int,int>,int>>> q;
	// queue<pair<pair<int,int>,pair<int,int>>> q;
	q.push({{curY,curX},{{curK,1},0}});
	visited[curY][curX][curK][0]=1;
	
	while(!q.empty()){
		int y=q.front().first.first;
		int x=q.front().first.second;
		int k=q.front().second.first.first;
		int cnt=q.front().second.first.second;
		int flag=q.front().second.second;
		
		// cout<<y<<" "<<x<<" "<<k<<" "<<cnt<<endl;
		q.pop();
		if(y==N-1 && x==M-1){
			return cnt;
		}
		if(!visited[y][x][k][!flag]){
			visited[y][x][k][!flag]=1;
			q.push({{y,x},{{k,cnt+1},!flag}});
		}
		for(int i=0;i<4;++i){
			int ny=y+dy[i];
			int nx=x+dx[i];
			
			if(isRange(ny,nx) && !visited[ny][nx][k][!flag]){
				if(board[ny][nx]=='0'){
					// cout<<ny<<" "<<nx<<" "<<k<<" "<<cnt<<endl;
					q.push({{ny,nx},{{k,cnt+1},!flag}});
					
					visited[ny][nx][k][!flag]=1;
				}
			}
			if(isRange(ny,nx) && k>0 && !visited[ny][nx][k-1][!flag]){
				if(board[ny][nx]=='1' && flag==0){
					q.push({{ny,nx},{{k-1,cnt+1},1}});
					
					visited[ny][nx][k-1][!flag]=1;
				}
			}	
		}
			
		
	}
	return -1;
}


int main() {
	// your code goes here
	Input();
	cout<<BFS(0,0,K);
	return 0;
}