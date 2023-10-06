#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int N,M;
int min_num=122232421;
const int MAX=6+2;
int board[MAX][MAX];
int dy[3]={1,1,1};
int dx[3]={-1,0,1};
bool visited[MAX][MAX][3]; //{x,y}에 dir방향으로 도착했을 때

void Input(){
	cin>>N>>M;
	for(int i=0;i<MAX;++i){
		for(int j=0;j<MAX;++j){
			board[i][j]=0;
		}
	}
	for(int i=1;i<=N;++i){
		for(int j=0;j<M;++j){
			cin>>board[i][j];
		}
	}
}
void dfs(int y, int x, int cur_dir, int cur_sum){
	if(cur_dir==-1){
		for(int i=0;i<3;++i){
			dfs(y,x,i,cur_sum);
		}
		return;
	}
	if(y==N+1){
		min_num=min(min_num,cur_sum);
		return;
	}
	for(int next_dir=0;next_dir<3;++next_dir){
		if(next_dir==cur_dir) continue;
		int ny=y+dy[cur_dir];
		int nx=x+dx[cur_dir];
		if(nx<0 || nx>=M) continue;
		dfs(ny,nx,next_dir,cur_sum+board[y][x]);
		// if(ny==N+1){

		// }
		// if(!visited[ny][nx][next_dir]){
		// 	visited[ny][nx][]
		// }
	}

}
void solve(){
	for(int i=0;i<M;++i){
		dfs(0,i,-1,0);	
	}
	cout<<min_num;
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