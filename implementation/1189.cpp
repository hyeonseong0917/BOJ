#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX=5+1;
char board[MAX][MAX];
bool visited[MAX][MAX];
int R,C,K;
void Input(){
	cin>>R>>C>>K;
	for(int i=0;i<R;++i){
		for(int j=0;j<C;++j){
			cin>>board[i][j];
		}
	}
}
int ans=0;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<R && x<C);
}
void dfs(int y, int x, int cnt){
	if(y==0 && x==C-1){
		// cout<<cnt<<endl;
		if(cnt==K){
			++ans;
		}
		return;
	}
	for(int i=0;i<4;++i){
		int ny=y+dy[i];
		int nx=x+dx[i];
		if(isRange(ny,nx) && !visited[ny][nx] && board[ny][nx]=='.'){
			visited[ny][nx]=1;
			dfs(ny,nx,cnt+1);
			visited[ny][nx]=0;
		}
	}
}

void solve(){
	visited[R-1][0]=1;
	dfs(R-1,0,1);
	cout<<ans;
}

int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}