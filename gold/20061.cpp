#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

int N;
vector<pair<int,pair<int,int>>> v;
const int MAX=9+1;
int board[MAX][MAX];
int score=0;
void Input(){
	cin>>N;
	for(int i=0;i<N;++i){
		int a,b,c;
		cin>>a>>b>>c;
		v.push_back({a,{b,c}});
	}
}
void blue_check_full(){
	while(1){
		bool is_fin=1;
		for(int i=9;i>=6;--i){
			// i번째 열이 차있는지?
			bool blue_flag=0;
			for(int j=0;j<4;++j){
				if(board[j][i]==0){
					blue_flag=1;
					break;
				}
			}
			if(!blue_flag){
				++score;
				is_fin=0;
				for(int j=0;j<4;++j){
					board[j][i]=0;
				}
				for(int j=i;j>=5;--j){
					for(int k=0;k<4;++k){
						board[k][j]=board[k][j-1];
						board[k][j-1]=0;
					}
				}
				break;
			}
		}
		if(is_fin){
			break;
		}
	}
	// 4 5열에 타일 존재?
	int cnt=0;
	for(int i=0;i<4;++i){
		if(board[i][4]==1){
			++cnt;
			break;
		}
	}
	for(int i=0;i<4;++i){
		if(board[i][5]==1){
			++cnt;
			break;
		}
	}
	if(cnt==0){
		return;
	}
	while(cnt--){
		for(int i=0;i<4;++i){
			board[i][9]=0;
		}
		for(int i=9;i>=5;--i){
			for(int j=0;j<4;++j){
				board[j][i]=board[j][i-1];
				board[j][i-1]=0;
			}
		}
	}
}
void green_check_full(){
	// 초록
	// 중력 작용
	while(1){
		bool is_fin=1;
		for(int i=9;i>=6;--i){
			// i번째 줄이 차있는지?
			bool green_flag=0;
			for(int j=0;j<4;++j){
				if(board[i][j]==0){
					green_flag=1;
					break;
				}
			}
			if(!green_flag){
				// i번째 줄이 차 있음
				++score;
				for(int j=0;j<4;++j){
					board[i][j]=0;
				}
				for(int j=i;j>=5;--j){
					for(int k=0;k<4;++k){
						board[j][k]=board[j-1][k];
						board[j-1][k]=0;
					}
					
				}
				is_fin=0;
				break;
			}
		}	
		if(is_fin){
			break;
		}
	}
	// 4 5 행에 타일 존재?
	int cnt=0;
	for(int i=0;i<4;++i){
		if(board[4][i]==1){
			++cnt;
			break;
		}
	}
	for(int i=0;i<4;++i){
		if(board[5][i]==1){
			++cnt;
			break;
		}
	}
	if(cnt==0){
		return;
	}
	while(cnt--){
		for(int i=0;i<4;++i){
			board[9][i]=0;
		}
		for(int i=9;i>=5;--i){
			for(int j=0;j<4;++j){
				board[i][j]=board[i-1][j];
				board[i-1][j]=0;
			}
		}
	}
}
void move_block(int t, int x, int y){
	// (x,y)에서 t에 해당하는 블록을 이동
	if(t==1){
		// 초록
		board[5][y]=1;
		for(int i=6;i<=9;++i){
			if(board[i][y]==0){
				board[i][y]=1;
				board[i-1][y]=0;
			}else{
				break;
			}
		}
		// 파랑
		board[x][5]=1;
		for(int i=6;i<=9;++i){
			if(board[x][i]==0){
				board[x][i]=1;
				board[x][i-1]=0;
			}else{
				break;
			}
		}
	}else if(t==2){
		// 초록
		board[5][y]=1;
		board[5][y+1]=1;
		for(int i=6;i<=9;++i){
			if(board[i][y]==0 && board[i][y+1]==0){
				board[i][y]=1;
				board[i][y+1]=1;
				board[i-1][y]=0;
				board[i-1][y+1]=0;
			}else{
				break;
			}
		}
		// 파랑
		board[x][4]=1;
		board[x][5]=1;
		for(int i=6;i<=9;++i){
			if(board[x][i]==0){
				board[x][i]=1;
				board[x][i-1]=1;
				board[x][i-2]=0;
			}else{
				break;
			}
		}
	}else{
		// 초록
		board[4][y]=1;
		board[5][y]=1;
		for(int i=6;i<=9;++i){
			if(board[i][y]==0){
				board[i][y]=1;
				board[i-1][y]=1;
				board[i-2][y]=0;
			}else{
				break;
			}
		}
		// 파랑
		board[x][5]=1;
		board[x+1][5]=1;
		for(int i=6;i<=9;++i){
			if(board[x][i]==0 && board[x+1][i]==0){
				board[x][i]=1;
				board[x+1][i]=1;
				board[x][i-1]=0;
				board[x+1][i-1]=0;
			}else{
				break;
			}
		}
	}

}
void solve(){
	for(int i=0;i<MAX;++i){
		for(int j=0;j<MAX;++j){
			board[i][j]=0;
		}
	}
	for(int i=0;i<N;++i){
		int t=v[i].first;
		int x=v[i].second.first;
		int y=v[i].second.second;
		move_block(t,x,y);
		green_check_full();
		blue_check_full();
	}
	int tile_cnt=0;
	for(int i=0;i<MAX;++i){
		for(int j=0;j<MAX;++j){
			if(board[i][j]==1){
				++tile_cnt;
			}
		}
	}
	cout<<score<<"\n";
	cout<<tile_cnt;
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