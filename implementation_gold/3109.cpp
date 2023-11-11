#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

int R,C;
char board[10000+10][500+10];
bool check[10000+10][500+10][3+1]; //[y][x]에 dir방향으로 들어옴
bool visited[10000+10][500+10];
int dy[3]={-1,0,1};
int dx[3]={1,1,1};
void Input(){
	cin>>R>>C;
	for(int i=0;i<R;++i){
		for(int j=0;j<C;++j){
			cin>>board[i][j];
			for(int k=0;k<4;++k){
				check[i][j][k]=0;
			}
			visited[i][j]=0;
		}
	}
}
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<R && x<C);
}
int cnt=0;
bool flag=0;
void dfs(int y, int x, int dir){
	if(flag==1){
		return;
	}
	// cout<<y<<" "<<x<<endl;
	if(x==C-1){
		if(!flag && !visited[y][x]){
			visited[y][x]=1;
			flag=1;
			// cout<<y<<" "<<x<<endl;
			++cnt;
		}
		
		return;
	}
	for(int i=0;i<3;++i){
		int ny=y+dy[i];
		int nx=x+dx[i];
		if(!isRange(ny,nx)) continue;
		if(check[ny][nx][i]) continue;
		if(board[ny][nx]=='x') continue;
		
		check[ny][nx][i]=1;
		dfs(ny,nx,i);
	}
}
void solve(){
	for(int i=0;i<R;++i){
		flag=0;
		dfs(i,0,0);
	}
}


int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	Input();
	solve();
	cout<<cnt;	
	return 0;
}