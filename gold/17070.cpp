#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define ll long long
#define MAX_NUM 16+1
int n;
int board[MAX_NUM][MAX_NUM];
bool check[MAX_NUM][MAX_NUM];
// 0,1,2
int dy[3]={0,1,1};
int dx[3]={1,0,1};
int ans=0;
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<n && x<n);
}
void Init(){
	ans=0;
	for(int i=0;i<MAX_NUM;++i){
		for(int j=0;j<MAX_NUM;++j){
			board[i][j]=0;
			check[i][j]=0;
		}
	}
}
void Input(){
	cin>>n;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			cin>>board[i][j];
		}
	}
}
void dfs(int y, int x, int dir){
	// cout<<y<<" "<<x<<" "<<dir<<endl;
	if(y==n-1 && x==n-1){
		++ans;
		return;
	}
	for(int i=0;i<3;++i){
		if(dir==0 && i==1) continue;
		if(dir==1 && i==0) continue;
		int ny=y+dy[i];
		int nx=x+dx[i];
		if(!isRange(ny,nx)) continue;
		if(board[ny][nx]) continue;
		if(check[ny][nx]) continue;
		// 방금까지 dir방향이었는데, i방향으로 밀 수 있는지?
		if(i==2){
			// 대각선인경우
			bool flag=0;
			for(int j=0;j<2;++j){
				int nny=y+dy[j];
				int nnx=x+dx[j];
				if(board[nny][nnx] || check[nny][nnx]){
					flag=1;
					break;
				}
			}
			if(!flag){
				for(int j=0;j<3;++j){
					int nny=y+dy[j];
					int nnx=x+dx[j];
					check[nny][nnx]=1;
				}	
				dfs(ny,nx,2);
				for(int j=0;j<3;++j){
					int nny=y+dy[j];
					int nnx=x+dx[j];
					check[nny][nnx]=0;
				}	
			}
		}else{
			// 가로나 세로
			if(!check[ny][nx] && !board[ny][nx]){
				check[ny][nx]=1;
				dfs(ny,nx,i);
				check[ny][nx]=0;
			}
		}
	}
}
void solve(){
	check[0][1]=1;
	dfs(0,1,0);
}
int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	for(ll o=1;o<=1;++o){
		Init();
		Input();
		solve();
		cout<<ans;
	}
	return 0;
}