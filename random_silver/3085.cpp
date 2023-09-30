#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

const int MAX=50+1;
char board[MAX][MAX];
char tmp_board[MAX][MAX];
bool visited[MAX][MAX];
int dy[2]={0,1};
int dx[2]={1,0};
int N;
void Input(){
	cin>>N;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin>>board[i][j];
			tmp_board[i][j]=board[i][j];
		}
	}
}
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<N && x<N);
}
int max_num=-1;
void dfs(int y, int x, int cnt, int dir){
	max_num=max(max_num,cnt);
	// dir이 0인경우 오른쪽으로만
	int ny=y+dy[dir];
	int nx=x+dx[dir];
	if(board[ny][nx]==board[y][x]){
		dfs(ny,nx,cnt+1,dir);
	}
}

void solve(){
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			// -- |
			//    |
			// init
			for(int k=0;k<N;++k){
				for(int p=0;p<N;++p){
					board[k][p]=tmp_board[k][p];
					visited[k][p]=0;
				}
			}
			// 오른쪽 칸이 존재할 경우 오른쪽 칸과 교체
			if(j+1<N && board[i][j]!=board[i][j+1]){
				char c=board[i][j+1];
				board[i][j+1]=board[i][j];
				board[i][j]=c;
				for(int k=0;k<N;++k){
					for(int p=0;p<N;++p){
						dfs(k,p,1,0);
						dfs(k,p,1,1);
					}
				}
			}
			for(int k=0;k<N;++k){
				for(int p=0;p<N;++p){
					board[k][p]=tmp_board[k][p];
					visited[k][p]=0;
				}
			}
			// 아래쪽 칸이 존재할 경우 아래쪽 칸과 교체
			if(i+1<N && board[i][j]!=board[i+1][j]){
				char c=board[i+1][j];
				board[i+1][j]=board[i][j];
				board[i][j]=c;
				for(int k=0;k<N;++k){
					for(int p=0;p<N;++p){
						dfs(k,p,1,0);
						dfs(k,p,1,1);
					}
				}
			}
		}
	}
	cout<<max_num;
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