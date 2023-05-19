#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N,M=0;
const int MAX=50+1;
int board[MAX][MAX];
bool visited[MAX][MAX];
int dy[8]={-1,-1,0,1,1,1,0,-1};
int dx[8]={0,1,1,1,0,-1,-1,-1};
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<N && x<M);
}
int cnt=0;
void dfs(int y, int x){
	for(int i=0;i<8;++i){
		int ny=y+dy[i];
		int nx=x+dx[i];
		if(isRange(ny,nx) && !visited[ny][nx] && board[ny][nx]==1){
			visited[ny][nx]=1;
			dfs(ny,nx);
		}
	}
}
int main() {
	// your code goes here
	while(1){
		M=0,N=0;
		cin>>M>>N;
		if(M==0 && N==0){
			break;
		}
		cnt=0;
		for(int i=0;i<MAX;++i){
			for(int j=0;j<MAX;++j){
				board[i][j]=0;
				visited[i][j]=0;
			}
		}
		for(int i=0;i<N;++i){
			for(int j=0;j<M;++j){
				cin>>board[i][j];
			}
		}
		for(int i=0;i<N;++i){
			for(int j=0;j<M;++j){
				if(board[i][j]==1 && !visited[i][j]){
					visited[i][j]=1;
					dfs(i,j);
					++cnt;
				}
			}
		}
		cout<<cnt<<endl;
		
	}
	return 0;
}