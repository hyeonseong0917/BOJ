#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
using namespace std;



int R,C;
const int MAX=15+1;
char board[MAX][MAX];
bool is_goal[MAX][MAX];
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
string cmd;
pair<int,int> w;
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<R && x<C);
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int cnt=1;
	while(1){
		cin>>R>>C;
		if(R==0 && C==0){
			break;
		}
		for(int i=0;i<MAX;++i){
			for(int j=0;j<MAX;++j){
				board[i][j]='.';
				is_goal[i][j]=0;
			}
		}
		cmd="";
		for(int i=0;i<R;++i){
			for(int j=0;j<C;++j){
				cin>>board[i][j];
				if(board[i][j]=='w'){
					w.first=i;
					w.second=j;
					board[i][j]='.';
				}
				if(board[i][j]=='+'){
					board[i][j]='.';
					is_goal[i][j]=1;
				}
				if(board[i][j]=='W'){
					w.first=i;
					w.second=j;
					is_goal[i][j]=1;
					board[i][j]='.';
				}
				if(board[i][j]=='B'){
					is_goal[i][j]=1;
					board[i][j]='b';
				}

			}
		}
		cin>>cmd;
		bool flag=0;
		for(int i=0;i<cmd.size();++i){
			flag=0;
			int y=w.first;
			int x=w.second;
			int ny,nx;
			int dir=-1;
			if(cmd[i]=='U'){
				ny=y+dy[0];
				nx=x+dx[0];
				dir=0;
			}else if(cmd[i]=='R'){
				ny=y+dy[1];
				nx=x+dx[1];
				dir=1;
			}else if(cmd[i]=='D'){
				ny=y+dy[2];
				nx=x+dx[2];
				dir=2;
			}else if(cmd[i]=='L'){
				ny=y+dy[3];
				nx=x+dx[3];
				dir=3;
			}
			if(board[ny][nx]=='#') continue;
			if(board[ny][nx]=='b'){
				if(board[ny+dy[dir]][nx+dx[dir]]!='.'){
					continue;
				}else{
					board[ny+dy[dir]][nx+dx[dir]]='b';
					board[ny][nx]='.';
					w.first=ny;
					w.second=nx;
					for(int j=0;j<R;++j){
						for(int k=0;k<C;++k){
							if(board[j][k]=='b' && !is_goal[j][k]){
								flag=1;
								break;
							}
						}
					}
				}
			}else{
				w.first=ny;
				w.second=nx;
				continue;
			}
			if(!flag){
				break;
			}
		}

		if(!flag){
			for(int i=0;i<R;++i){
				for(int j=0;j<C;++j){
					if(board[i][j]!='#'){
						board[i][j]='.';
					}
				}
			}
			board[w.first][w.second]='w';
			for(int i=0;i<R;++i){
				for(int j=0;j<C;++j){
					if(is_goal[i][j]){
						board[i][j]='B';
					}
				}
			}
			cout<<"Game "<<cnt<<": complete"<<"\n";
			for(int i=0;i<R;++i){
				for(int j=0;j<C;++j){
					cout<<board[i][j];
				}cout<<"\n";
			}
		}else{
			for(int i=0;i<R;++i){
				for(int j=0;j<C;++j){
					if(board[i][j]=='b' && is_goal[i][j]){
						board[i][j]='B';
					}
					if(board[i][j]=='.' && is_goal[i][j]){
						board[i][j]='+';
					}
				}
			}
			if(is_goal[w.first][w.second]){
				board[w.first][w.second]='W';
			}else{
				board[w.first][w.second]='w';
			}
			cout<<"Game "<<cnt<<": incomplete"<<"\n";
			for(int i=0;i<R;++i){
				for(int j=0;j<C;++j){
					cout<<board[i][j];
				}cout<<"\n";
			}
		}
		++cnt;

	}
	
	return 0;
}