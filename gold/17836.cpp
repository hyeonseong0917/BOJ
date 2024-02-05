#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

#define ll long long

int N,M,T;
const int MAX=100+1;
int board[MAX][MAX];
bool visited[MAX][MAX][2];
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<N && x<M);
}
void Input(){
	cin>>N>>M>>T;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			cin>>board[i][j];
		}
	}
}
int BFS(){
	queue<pair<pair<int,int>,pair<int,int>>> q;
	q.push({{0,0},{0,0}});
	visited[0][0][0]=1;
	// y,x,cnt,isWeapon
	while(!q.empty()){
		int y=q.front().first.first;
		int x=q.front().first.second;
		int cnt=q.front().second.first;
		int isWeapon=q.front().second.second;
		// cout<<y<<" "<<x<<" "<<cnt<<endl;
		q.pop();
		if(y==N-1 && x==M-1){
			return cnt;
		}
		for(int i=0;i<4;++i){
			int ny=y+dy[i];
			int nx=x+dx[i];
			if(!isRange(ny,nx)) continue;
			if(visited[ny][nx][isWeapon]) continue;
			if(!isWeapon){
				if(board[ny][nx]==1) continue;
				if(board[ny][nx]==2){
					q.push({{ny,nx},{cnt+1,1}});
				}else{
					q.push({{ny,nx},{cnt+1,isWeapon}});
				}
			}else{
				q.push({{ny,nx},{cnt+1,isWeapon}});
			}
			visited[ny][nx][isWeapon]=1;
		}
	}
	return -1;
}
void solve(){
	int cur_num=BFS();
	if(cur_num==-1 || cur_num>T){
		cout<<"Fail";
	}else{
		cout<<cur_num;
	}
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