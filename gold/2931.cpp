#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

const int MAX=25+1;
string board[MAX];
int R,C;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int y,x,dir;
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<R && x<C);
}
void Input(){
	cin>>R>>C;
	for(int i=0;i<R;++i){
		cin>>board[i];
		for(int j=0;j<C;++j){
			if(board[i][j]=='M'){
				y=i;
				x=j;
			}
		}
	}
}
int change_dir(int dir, char c){
	if(c=='|'){
		if(dir==0 || dir==2){
			return dir;
		}
	}
	if(c=='-'){
		if(dir==1 || dir==3){
			return dir;
		}
	}
	if(c=='+'){
		if(dir==0 || dir==2){
			return dir;
		}
		if(dir==3 || dir==1){
			return dir;
		}
	}
	if(c=='1'){
		if(dir==3){
			return 2;
		}
		if(dir==0){
			return 1;
		}
	}
	if(c=='2'){
		if(dir==2){
			return 1;
		}
		if(dir==3){
			return 0;
		}
	}
	if(c=='3'){
		if(dir==1){
			return 0;
		}
		if(dir==2){
			return 3;
		}
	}
	if(c=='4'){
		if(dir==1){
			return 2;
		}
		if(dir==0){
			return 3;
		}
	}
	return -1;
}
int visited[MAX][MAX];
void solve(){
	for(int i=0;i<MAX;++i){
		for(int j=0;j<MAX;++j){
			visited[i][j]=0;
		}
	}
	// 초기 방향 정하기
	for(int i=0;i<4;++i){
		int ny=y+dy[i];
		int nx=x+dx[i];
		if(!isRange(ny,nx)) continue;
		if(board[ny][nx]!='.'){
			int cur_dir=change_dir(i,board[ny][nx]);
			if(cur_dir!=-1){
				dir=i;
			}
		}
	}
	++visited[y][x];
	// cout<<dir;
	while(1){
		y+=dy[dir];
		x+=dx[dir];
		++visited[y][x];
		if(board[y][x]=='.'){
			// cout<<y<<" "<<x;
			break;
		}
		dir=change_dir(dir,board[y][x]);
	}
	// cout<<dir<<endl;
	int new_dir=-1;
	vector<int> can_dir;
	// 현재 방향 dir
	for(int i=0;i<4;++i){
		if(i==(dir+2)%4) continue;
		int ny=y+dy[i];
		int nx=x+dx[i];
		if(!isRange(ny,nx)) continue;
		if(board[ny][nx]!='.'){
			int cur_dir=change_dir(i,board[ny][nx]);
			if(cur_dir!=-1){
				// new_dir=i;
				can_dir.push_back(i);
				// cout<<dir<<endl;
			}
		}
	}
	// cout<<can_dir[0]<<endl;
	char pipe[7]={'|','-','+','1','2','3','4'};
	char origin_pipe;
	vector<char> can_pipe;
	for(int i=0;i<can_dir.size();++i){
		int cur_dir=can_dir[i];
		// dir에서 cur_dir로 바꿀 수 있는 pipe의 개수?
		for(int j=0;j<7;++j){
			if(change_dir(dir,pipe[j])==cur_dir){
				can_pipe.push_back(pipe[j]);
			}
		}
	}
	// cout<<can_pipe.size();
	
	int tmp_visited[MAX][MAX];
	for(int i=0;i<can_pipe.size();++i){
		bool flag=0;
		board[y][x]=can_pipe[i];
		int tmp_y=y;
		int tmp_x=x;
		int tmp_dir=dir;
		for(int j=0;j<MAX;++j){
			for(int k=0;k<MAX;++k){
				tmp_visited[j][k]=visited[j][k];
			}
		}
		dir=change_dir(dir,can_pipe[i]);
		while(1){
			y+=dy[dir];
			x+=dx[dir];
			++visited[y][x];
			if(board[y][x]=='Z'){
				flag=1;
				break;
			}
			dir=change_dir(dir,board[y][x]);
			if(dir==-1){
				break;
			}
		}
		if(flag){
			bool all_visited=1;
			for(int j=0;j<R;++j){
				for(int k=0;k<C;++k){
					if(board[j][k]!='.'){
						if(board[j][k]=='+'){
							if(visited[j][k]!=2){
								all_visited=0;
							}
						}else{
							if(!visited[j][k]){
								all_visited=0;		
							}
						}
					}
				}
			}
			if(all_visited){
				cout<<tmp_y+1<<" "<<tmp_x+1<<" "<<can_pipe[i];
			}
		}
		y=tmp_y;
		x=tmp_x;
		dir=tmp_dir;
		for(int j=0;j<MAX;++j){
			for(int k=0;k<MAX;++k){
				visited[j][k]=tmp_visited[j][k];
			}
		}
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