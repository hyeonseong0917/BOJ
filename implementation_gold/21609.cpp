#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
	
	// 검: -1, 무지개: 0, w=일반: m가지 색 존재(1~m)
	// 블록 그룹(2개 이상의 블록이 이어져 있어야 함)
	// - 연결된 블록 집합, 일반 블록 무조건 한 개,여러 개인 경우 색 같아야함
	// - 검은색 블록 x
	// - 무지개 블록 상관 x
	// - 기준 블록: 행,열이 가장 작은 일반 블록
	// 오토 플레이: 블록 그룹이 존재하는 동안 계속
	// - 1. 크기가 가장 큰 블록 그룹 -> 같으면 무지개 블록 많은 그룹 -> 기준 블록의 행이 가장 큰 것 -> 기준 블록의 열이 가장 큰 것
	// - 2. 블록 그룹의 블록 제거, 블록 수^2만큼 점수 획득
	// - 3. 중력 작용
	// - 4. 반시계 회전
	// - 5. 중력 작용
	
int N,M;
const int MAX=20+1;
int board[MAX][MAX];
int tmp_board[MAX][MAX];
void Input(){
	cin>>N>>M;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin>>board[i][j];
			tmp_board[i][j]=board[i][j];
		}
	}
}
// ->, |
//     V
bool visited[MAX][MAX];
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};;
// 크기가 가장 큰 블록 그룹 찾기
pair<pair<int,int>,pair<int,int>> p={{0,0},{0,0}}; //{ 무지개 블록 개수,cnt}, {y,x}
vector<pair<int,int>> tmp_pos;
vector<pair<int,int>> pos;
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<N && x<N);
}
// 초기 색상=board[init_y][init_x],
int cnt=0;
int rainbow_cnt=0;
void dfs(int board_num, int init_y, int init_x, int y, int x){
	++cnt;
	
	for(int i=0;i<4;++i){
		int ny=y+dy[i];
		int nx=x+dx[i];
		if(!isRange(ny,nx)) continue;
		if(!visited[ny][nx] && (board[ny][nx]==board_num || board[ny][nx]==0)){
			if(board[ny][nx]==0){
				++rainbow_cnt;
			}
			visited[ny][nx]=1;
			if(init_y>ny){
				init_y=ny;
				init_x=nx;
			}else if(init_y==ny){
				init_x=min(init_x,nx);
			}
			tmp_pos.push_back({ny,nx});
			dfs(board_num,init_y,init_x,ny,nx);
		}
	}
}

// 중력 작용
void gravity(){
	for(int i=0;i<N;++i){
		for(int j=N-1;j>=0;--j){
			if(board[j][i]!=-1 && board[j][i]!=-2){
				int y=j;
				int x=i;
				while(1){
					++y;
					if(y>=N || board[y][x]!=-2){
						--y;
						break;
					}
				}
				if(y==j) continue;
				board[y][x]=board[j][i];
				board[j][i]=-2;
			}
		}
	}
	// cout<<endl;
	// for(int i=0;i<N;++i){
	// 	for(int j=0;j<N;++j){
	// 		cout<<board[i][j]<<" ";
	// 	}cout<<endl;
	// }
}

// 반시계 회전
void opp_clock(){
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			tmp_board[i][j]=board[i][j];
		}
	}
	for(int i=0;i<N;++i){
		for(int j=N-1;j>=0;--j){
			board[N-1-j][i]=tmp_board[i][j];
		}
	}
	// cout<<endl;
	// for(int i=0;i<N;++i){
	// 	for(int j=0;j<N;++j){
	// 		cout<<board[i][j]<<" ";
	// 	}cout<<endl;
	// }
}

void solve(){
	int ans=0;
	// gravity();
	// opp_clock();
	int t=0;
	while(1){
		// 크기가 가장 큰 블록 그룹 찾기, 블록 그룹 정보와 무지개 블록 수, 기준 블록의 행,열 정보 포함해야
		// ++t;
		// if(t==4){
		// 	break;
		// }
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j){
				visited[i][j]=0;
			}
		}
		p={{0,0},{0,0}};
		pos.clear();
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j){
				if(!visited[i][j] && board[i][j]>0){
					visited[i][j]=1;
					cnt=0;
					rainbow_cnt=0;
					tmp_pos.clear();
					for(int u=0;u<N;++u){
						for(int v=0;v<N;++v){
							if(board[u][v]==0){
								visited[u][v]=0;
							}
						}
					}

					tmp_pos.push_back({i,j});
					dfs(board[i][j],i,j,i,j);
					if(cnt>p.first.second){
						p.first.first=rainbow_cnt;
						p.first.second=cnt;
						p.second.first=i;
						p.second.second=j;
						pos=tmp_pos;
					}else if(cnt==p.first.second){
						if(rainbow_cnt>p.first.first){
							p.first.first=rainbow_cnt;
							p.first.second=cnt;
							p.second.first=i;
							p.second.second=j;
							pos=tmp_pos;	
						}else if(rainbow_cnt==p.first.first){
							// cout<<rainbow_cnt<<" "<<y<<" "<<x<<endl;
							if(i>p.second.first){
								p.first.first=rainbow_cnt;
								p.first.second=cnt;
								p.second.first=i;
								p.second.second=j;
								pos=tmp_pos;	
							}else if(i==p.second.first){
								if(j>p.second.second){
									p.first.first=rainbow_cnt;
									p.first.second=cnt;
									p.second.first=i;
									p.second.second=j;
									pos=tmp_pos;	
								}
							}
						}		
					}
					// cout<<i<<" "<<j<<" "<<cnt<<endl;
				}
			}
		}
		if(p.first.second<=1){
			break;
		}
		// cout<<p.first<<" "<<p.second.first<<" "<<p.second.second;
		// for(int i=0;i<pos.size();++i){
		// 	cout<<pos[i].first<<" "<<pos[i].second<<endl;
		// }
		// 빈 칸을 -2라고 정의
		// board의 블록 그룹 위치를 -2로 채우기
		for(int i=0;i<pos.size();++i){
			board[pos[i].first][pos[i].second]=-2;
		}
		// ans에 블록 그룹 사이즈 ^2 더해줌
		ans+=pos.size()*pos.size();
		// 중력 작용
		// cout<<endl;
		// for(int i=0;i<N;++i){
		// 	for(int j=0;j<N;++j){
		// 		cout<<board[i][j]<<" ";
		// 	}cout<<endl;
		// }
		gravity();
		opp_clock();
		gravity();
		// cout<<endl;
		// for(int i=0;i<N;++i){
		// 	for(int j=0;j<N;++j){
		// 		cout<<board[i][j]<<" ";
		// 	}cout<<endl;
		// }
		// cout<<pos.size()<<endl;
		// break;
		// break;
		// cout<<ans<<endl;
	}
	cout<<ans;
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