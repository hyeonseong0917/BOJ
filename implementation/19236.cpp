#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int MAX=4+1;
int board[MAX][MAX];
int board_dir[MAX][MAX];
vector<int> eat_num;
int dy[8]={-1,-1,0,1,1,1,0,-1};
int dx[8]={0,-1,-1,-1,0,1,1,1};
pair<pair<int,int>,int> shark;
vector<pair<pair<int,int>,pair<int,int>>> fish[16+1];
//물고기의 좌표

void Input(){
	for(int i=0;i<MAX;++i){
		for(int j=0;j<MAX;++j){
			board[i][j]=0;
			board_dir[i][j]=0;
		}
	}
	for(int i=0;i<4;++i){
		for(int j=0;j<8;++j){
			if(j%2==1){//1 3 5 7
				cin>>board_dir[i][j/2];
				--board_dir[i][j/2];
			}else{//0 2 4 6
				cin>>board[i][j/2];
			}
		}
	}
	for(int i=0;i<4;++i){
		for(int j=0;j<4;++j){
			fish[board[i][j]].push_back({{i,j},{board_dir[i][j],1}});
		}
	}
	
}
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<4 && x<4);
}

void fish_move(){
	for(int i=1;i<=16;++i){
		if(fish[i][0].second.second){
			int cur_y=fish[i][0].first.first;
			int cur_x=fish[i][0].first.second;
			int cur_dir=fish[i][0].second.first;
			bool flag=0;
			for(int j=0;j<=7;++j){
				if(flag==1) break;
				int next_dir=cur_dir+j;
				if(next_dir>=8){
					next_dir-=8;
				}
				int ny=cur_y+dy[next_dir];
				int nx=cur_x+dx[next_dir];
				if(!isRange(ny,nx)) continue;
				if(ny==shark.first.first && nx==shark.first.second) continue;
				if(board[ny][nx]==-1){
					//물고기가 없는 경우
					flag=1;
					fish[i][0]={{ny,nx},{next_dir,1}};
					board[ny][nx]=board[cur_y][cur_x];
					board[cur_y][cur_x]=-1;
				}else{
					//물고기 존재
					flag=1;
					fish[i][0].second.first=next_dir;
					pair<pair<int,int>,pair<int,int>> tmp;
					tmp=fish[board[ny][nx]][0];
					int tmp_num=board[ny][nx];
					fish[board[ny][nx]][0].first={cur_y,cur_x};
					fish[i][0].first=tmp.first;
					board[ny][nx]=board[cur_y][cur_x];
					board[cur_y][cur_x]=tmp_num;
				}
			}
		}
	}	
}


int maxNum=-122232421;

void dfs(int y, int x, int dir){
	bool finish=1;
	for(int i=1;i<=3;++i){
		int ny=y+dy[dir]*i;
		int nx=x+dx[dir]*i;
		if(!isRange(ny,nx)) continue;
		if(board[ny][nx]!=-1){
			finish=0;
			break;
		}
	}
	if(finish==1){
		int sum=0;
		for(int i=0;i<eat_num.size();++i){
			// cout<<eat_num[i]<<" ";
			sum+=eat_num[i];
		}
		maxNum=max(sum,maxNum);
		return;
	}
	for(int i=1;i<=3;++i){
		int ny=y+dy[dir]*i;
		int nx=x+dx[dir]*i;
		
		if(!isRange(ny,nx)) continue;
		if(board[ny][nx]==-1) continue;
		// cout<<ny<<" "<<nx<<" "<<board[ny][nx]<<endl;
		// return;
		pair<pair<int,int>,int> tmp_shark;
		vector<pair<pair<int,int>,pair<int,int>>> tmp_fish[16+1];
		int tmp_board[4][4];
		tmp_shark=shark;
		for(int j=1;j<=16;++j){
			tmp_fish[j]=fish[j];
		}
		for(int j=0;j<4;++j){
			for(int k=0;k<4;++k){
				tmp_board[j][k]=board[j][k];
			}
		}
		shark.first.first=ny;
		shark.first.second=nx;
		shark.second=fish[board[ny][nx]][0].second.first;
		eat_num.push_back(board[ny][nx]);
		fish[board[ny][nx]][0].second.second=0;
		board[ny][nx]=-1;
		fish_move();
		dfs(ny,nx,shark.second);
		shark=tmp_shark;
		eat_num.pop_back();
		for(int j=1;j<=16;++j){
			fish[j]=tmp_fish[j];
		}
		for(int j=0;j<4;++j){
			for(int k=0;k<4;++k){
				board[j][k]=tmp_board[j][k];
			}
		}
	}
}
void solve(){
	shark.first.first=0;
	shark.first.second=0;
	shark.second=fish[board[0][0]][0].second.first;
	fish[board[0][0]][0].second.second=0;
	eat_num.push_back(board[0][0]);
	board[0][0]=-1;
	fish_move();
	dfs(0,0,shark.second);
	cout<<maxNum;
}

int main() {
	// your code goes here
	Input();
	solve();
	
	
	return 0;
}