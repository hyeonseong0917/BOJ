#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


int N=0;
const int MAX=16+1;
int board[MAX][MAX];
int dy[3]={0,1,1};
int dx[3]={1,1,0};

bool isRange(int y, int x){
	return (y>=1 && x>=1 && y<=N && x<=N);
}
void Input(){
	cin>>N;
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			cin>>board[i][j];
		}
	}
}
int cnt=0;
// 가로 0 세로 1
int dy_0[2]={0,1};
int dx_0[2]={1,1};
int dy_1[2]={1,1};
int dx_1[2]={0,1};
int dy_t[4]={0,1,1,1};
int dx_t[4]={1,1,0,1};
int dy_2[3]={0,1,1};
int dx_2[3]={1,0,1};
void solve(int y, int x, int dir){
	if(y==N && x==N){
		++cnt;
		return;
	}
	if(dir==0 || dir==1){
		for(int i=0;i<2;++i){
			int ny=y+dy_t[i+dir*2];
			int nx=x+dx_t[i+dir*2];
			if(i==0){
				if(isRange(ny,nx) && board[ny][nx]==0){
					solve(ny,nx,dir);
				}
			}else{
				bool flag=0;
				for(int j=0;j<3;++j){
					int nny=y+dy[j];
					int nnx=x+dx[j];
					if(!isRange(nny,nnx) || board[nny][nnx]!=0){
						flag=1;
						break;
					}
				}
				if(flag==0){
					solve(ny,nx,2);
				}
			}
		}
	}else if(dir==2){
		for(int i=0;i<3;++i){
			int ny=y+dy_2[i];
			int nx=x+dx_2[i];
			if(i==0 || i==1){
				if(isRange(ny,nx) && board[ny][nx]==0){
					solve(ny,nx,i);
				}
			}else{
				bool flag=0;
				for(int j=0;j<3;++j){
					int nny=y+dy[j];
					int nnx=x+dx[j];
					if(!isRange(nny,nnx) || board[nny][nnx]!=0){
						flag=1;
						break;
					}
				}
				if(flag==0){
					solve(ny,nx,2);
				}
			}
		}
	}
	
}

int main() {
	// your code goes here
	Input();
	solve(1,2,0);
	cout<<cnt;
	return 0;
}