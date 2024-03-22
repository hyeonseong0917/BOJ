#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int R,C,N;
const int MAX=200+1;
char board[MAX][MAX];
void Input(){
	cin>>R>>C>>N;
	for(int i=0;i<R;++i){
		for(int j=0;j<C;++j){
			cin>>board[i][j];
		}
	}
	// N%=4;
	
}
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
bool isRange(int y, int x){
	return (y>=0 && x>=0 &&y<R && x<C);
}
void solve(){
	if(N%4==0 || N%4==2){
		for(int i=0;i<R;++i){
			for(int j=0;j<C;++j){
				cout<<"O";
			}cout<<endl;
		}
	}else if(N%4==1){
		if(N==1){
			for(int i=0;i<R;++i){
				for(int j=0;j<C;++j){
					cout<<board[i][j];
				}cout<<endl;
			}		
		}else{
			vector<pair<int,int>> pos;
			for(int i=0;i<R;++i){
				for(int j=0;j<C;++j){
					if(board[i][j]=='O'){
						pos.push_back({i,j});
					}
				}
			}
			for(int i=0;i<R;++i){
				for(int j=0;j<C;++j){
					board[i][j]='O';
				}
			}
			for(int i=0;i<pos.size();++i){
				int y=pos[i].first;
				int x=pos[i].second;
				board[y][x]='.';
				for(int j=0;j<4;++j){
					int ny=y+dy[j];
					int nx=x+dx[j];
					if(isRange(ny,nx)){
						board[ny][nx]='.';
					}
				}
			}
			pos.clear();
			for(int i=0;i<R;++i){
				for(int j=0;j<C;++j){
					if(board[i][j]=='O'){
						pos.push_back({i,j});
					}
				}
			}
			for(int i=0;i<R;++i){
				for(int j=0;j<C;++j){
					board[i][j]='O';
				}
			}
			// for(int i=0;i<R;++i){
			// 	for(int j=0;j<C;++j){
			// 		cout<<board[i][j];
			// 	}cout<<endl;
			// }
			// cout<<pos.size();
			for(int i=0;i<pos.size();++i){
				int y=pos[i].first;
				int x=pos[i].second;
				
				board[y][x]='.';
				for(int j=0;j<4;++j){
					int ny=y+dy[j];
					int nx=x+dx[j];
					if(isRange(ny,nx)){
						board[ny][nx]='.';
					}
				}
			}
			for(int i=0;i<R;++i){
				for(int j=0;j<C;++j){
					cout<<board[i][j];
				}cout<<endl;
			}
		}
		
	}else if(N%4==3){
		vector<pair<int,int>> pos;
		for(int i=0;i<R;++i){
			for(int j=0;j<C;++j){
				if(board[i][j]=='O'){
					pos.push_back({i,j});
				}
			}
		}	
		for(int i=0;i<R;++i){
			for(int j=0;j<C;++j){
				board[i][j]='O';
			}
		}
		for(int i=0;i<pos.size();++i){
			int y=pos[i].first;
			int x=pos[i].second;
			board[y][x]='.';
			for(int j=0;j<4;++j){
				int ny=y+dy[j];
				int nx=x+dx[j];
				if(isRange(ny,nx)){
					board[ny][nx]='.';
				}
			}
		}
		for(int i=0;i<R;++i){
			for(int j=0;j<C;++j){
				cout<<board[i][j];
			}cout<<endl;
		}
	}
}
int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}