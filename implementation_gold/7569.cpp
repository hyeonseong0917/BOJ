#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX=100+1;
int board[MAX][MAX][MAX];
int M,N,H;
vector<pair<int,pair<int,int>>> tomato;
int dz[6]={0,0,0,0,-1,1};
int dy[6]={-1,0,1,0,0,0};
int dx[6]={0,1,0,-1,0,0};
void Input(){
	cin>>M>>N>>H;
	for(int i=0;i<H;++i){
		for(int j=0;j<N;++j){
			for(int k=0;k<M;++k){
				cin>>board[i][j][k];
				if(board[i][j][k]==1){
					tomato.push_back({i,{j,k}});
				}
			}
		}
	}
}

bool isBoardClear(){
	for(int i=0;i<H;++i){
		for(int j=0;j<N;++j){
			for(int k=0;k<M;++k){
				if(board[i][j][k]==0){
					return 0;
				}
			}
		}
	}
	return 1;
}
bool isRange(int z, int y, int x){
	return (z>=0 && y>=0 && x>=0 && z<H && y<N && x<M);
}
int BFS(){
	if(isBoardClear()){
		return 0;
	}
	queue<pair<pair<int,int>,pair<int,int>>> q;
	bool visited[MAX][MAX][MAX];
	for(int i=0;i<H;++i){
		for(int j=0;j<N;++j){
			for(int k=0;k<M;++k){
				visited[i][j][k]=0;
			}
		}
	}
	for(int i=0;i<tomato.size();++i){
		int z=tomato[i].first;
		int y=tomato[i].second.first;
		int x=tomato[i].second.second;
		visited[z][y][x]=1;
		q.push({{z,y},{x,0}});
	}
	while(!q.empty()){
		int z=q.front().first.first;
		int y=q.front().first.second;
		int x=q.front().second.first;
		int cnt=q.front().second.second;
		q.pop();
		if(isBoardClear()){
			int maxNum=-1;
			for(int i=0;i<H;++i){
				for(int j=0;j<N;++j){
					for(int k=0;k<M;++k){
						maxNum=max(maxNum,board[i][j][k]);
					}
				}
			}
			return maxNum;
		}
		for(int i=0;i<6;++i){
			int nz=z+dz[i];
			int ny=y+dy[i];
			int nx=x+dx[i];
			if(!isRange(nz,ny,nx)) continue;
			if(board[nz][ny][nx]==0){
				board[nz][ny][nx]=cnt+1;
				q.push({{nz,ny},{nx,cnt+1}});
			}
		}
	}
	return -1;
}

int main() {
	// your code goes here
	Input();
	cout<<BFS();
	return 0;
}