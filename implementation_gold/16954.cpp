#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

const int MAX=8+1;
// char board[MAX][MAX];
vector<string> board;
int dy[8]={-1,-1,0,1,1,1,0,-1};
int dx[8]={0,1,1,1,0,-1,-1,-1};
map<vector<string>,int> m;
void Input(){
	for(int i=0;i<8;++i){
		string s="";
		for(int j=0;j<8;++j){
			char c;
			cin>>c;
			s+=c;
		}
		board.push_back(s);
	}
}
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<8 && x<8);
}
vector<string> Down(vector<string> cur_board){
	for(int i=0;i<8;++i){
		for(int j=7;j>=0;--j){
			if(cur_board[j][i]=='#' && isRange(j+1,i)){
				cur_board[j][i]='.';
				cur_board[j+1][i]='#';
			}
		}
	}
	return cur_board;
}

bool visited[8][8][50];

int BFS(){
	queue<pair<pair<vector<string>,int>,pair<int,int>>> q;
	q.push({{board,0},{7,0}});
	m[board]=1;
	visited[7][0][0]=1;
	while(!q.empty()){
		vector<string> cur_board=q.front().first.first;
		int cnt=q.front().first.second;
		int y=q.front().second.first;
		int x=q.front().second.second;
		if(y==0 && x==7){
			return 1;
		}
		q.pop();
		vector<string> new_board=Down(cur_board);
		// 이동하지 않는다면
		if(new_board[y][x]=='.' && !visited[y][x][cnt+1]){
			visited[y][x][cnt+1]=1;
			q.push({{new_board,cnt+1},{y,x}});
		}
		// 이동한다면
		for(int i=0;i<8;++i){
			int ny=y+dy[i];
			int nx=x+dx[i];
			if(!isRange(ny,nx)) continue;
			if(cur_board[ny][nx]=='.' && !visited[ny][nx][cnt+1] && new_board[ny][nx]=='.'){
				visited[ny][nx][cnt+1]=1;
				q.push({{new_board,cnt+1},{ny,nx}});
			}
		}
	}
	return 0;
}

void solve(){
	cout<<BFS();
}

int main() {
	// your code goes here
	Input();
	solve();
	
	return 0;
}