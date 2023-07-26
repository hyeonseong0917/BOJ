#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int N,K=0;
const int MAX=12+1;
int MAP[MAX][MAX];
int dy[4]={0,0,-1,1};
int dx[4]={1,-1,0,0};
map<pair<int,int>,vector<int>> board; //{{y,x},어떤 수들이 있는지}
vector<pair<pair<int,int>,pair<int,int>>> pos; //{{y,x},{번호,방향}}
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<N && x<N);
}
int turn_num=0;
void Input(){
	cin>>N>>K;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin>>MAP[i][j];
			//0 흰색
			//1 빨간색
			//2 파란색
			
		}
	}
	for(int i=0;i<K;++i){
		int curNum=i+1;
		int y,x,dir;
		cin>>y>>x>>dir;
		pos.push_back({{y-1,x-1},{curNum,dir-1}});
		board[{y-1,x-1}].push_back(curNum);
	}
}
void solve(){
	bool isClear=0;
	while(1){
		if(turn_num>1000){
			turn_num=-1;
			break;
		}
		//turn 진행
		for(int i=1;i<=K;++i){
			for(int j=0;j<pos.size();++j){
				if(pos[j].second.first==i){
					int y=pos[j].first.first;
					int x=pos[j].first.second;
					int num=pos[j].second.first;
					int dir=pos[j].second.second;
					
					int ny=y+dy[dir];
					int nx=x+dx[dir];
					bool next_flag=0;
					//파란색 칸 혹은 벗어나는 경우
					if(!isRange(ny,nx) || MAP[ny][nx]==2){
						//방향 전환
						if(dir==0){
							dir=1;
						}else if(dir==1){
							dir=0;
						}else if(dir==2){
							dir=3;
						}else if(dir==3){
							dir=2;
						}
						//ny nx 다시 계산
						ny=y+dy[dir];
						nx=x+dx[dir];
						//또 파란색 칸이거나 벗어날 경우 break
						if(!isRange(ny,nx) || MAP[ny][nx]==2){
							next_flag=1;
						}
					}
					pos[j].second.second=dir;
					if(next_flag==1){
						break;
					}
					//방향 전환이 된 상태, 다음 칸은 무조건 빨간칸 or 흰칸
					//이동할 말 결정
					vector<int> to_move;
					vector<int> board_vector=board[{y,x}];
					vector<int> tmp_board_vector;
					to_move.clear();
					tmp_board_vector.clear();
					bool kNext=0;
					for(int k=0;k<board_vector.size();++k){
						if(board_vector[k]==num){
							kNext=1;
						}
						if(kNext==1){
							to_move.push_back(board_vector[k]);
						}else{
							tmp_board_vector.push_back(board_vector[k]);
						}
					}
					
					if(to_move.size()==0){
						to_move.push_back(num);
					}
					board[{y,x}]=tmp_board_vector;
					
					if(MAP[ny][nx]==1){
						reverse(to_move.begin(),to_move.end());
					}
					for(int k=0;k<to_move.size();++k){
						board[{ny,nx}].push_back(to_move[k]);
					}
					for(int k=0;k<to_move.size();++k){
						int cur_num=to_move[k];
						for(int p=0;p<pos.size();++p){
							if(cur_num==pos[p].second.first){
								pos[p].first.first=ny;
								pos[p].first.second=nx;
								break;
							}
						}
					}
					
					break;
				}
			}
			for(int k=0;k<N;++k){
				for(int p=0;p<N;++p){
					if(board[{k,p}].size()>=4){
						isClear=1;
						break;
					}
				}	
				if(isClear==1){
					break;
				}
			}
			if(isClear==1){
				break;
			}
		}
		++turn_num;
		if(isClear==1){
			break;
		}
		
		
	}
	cout<<turn_num;
	
}

int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}