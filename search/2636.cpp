#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N,M=0;
const int MAX=100+1;
int board[MAX][MAX];
bool visited[MAX][MAX];
void Input(){
	cin>>N>>M;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			cin>>board[i][j];
		}
	}
}
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<N && x<M);
}
void BFS(){
	queue<pair<int,int>> q;
	queue<pair<int,int>> pq;
	int cnt=0;
	int s_size=0;
	while(1){
		q.push({0,0});
		for(int i=0;i<N;++i){
			for(int j=0;j<M;++j){
				visited[i][j]=0;
			}
		}
		int seg_cnt=0;
		while(!q.empty()){
			int y=q.front().first;
			int x=q.front().second;
			q.pop();
			for(int i=0;i<4;++i){
				int ny=y+dy[i];
				int nx=x+dx[i];
				if(isRange(ny,nx) && !visited[ny][nx]){
					visited[ny][nx]=1;
					if(board[ny][nx]==0){
						q.push({ny,nx});
					}else{
						board[ny][nx]=0;
						++seg_cnt;
					}
					
				}
			}
		}
		if(seg_cnt==0){
			cout<<cnt<<endl;
			cout<<s_size<<endl;
			return;
		}else{
			s_size=seg_cnt;
		}
		++cnt;
		
		
	}
	
}
int main() {
	// your code goes here
	Input();
	BFS();
	return 0;
}