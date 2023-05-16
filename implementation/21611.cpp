#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int N,M=0;
const int MAX=50+1;
int board[MAX][MAX];
vector<int> d;
vector<int> s;
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};
int dIdx[4]={2,1,3,0};
int Index[MAX][MAX]={0,};
int curY, curX=0;
map<int, pair<int,int>> m;

bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<N && x<N);
}
void Input(){
	cin>>N>>M;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin>>board[i][j];
		}
	}
	curY=N/2;
	curX=N/2;
	for(int i=0;i<M;++i){
		int a,b=0;
		cin>>a>>b;
		d.push_back(a-1);
		s.push_back(b);
	}
}
void index_set(){
	
	vector<int> Len;
	for(int i=1;i<=N-1;++i){
		if(i==N-1){
			Len.push_back(i);
			Len.push_back(i);
			Len.push_back(i);
		}else{
			Len.push_back(i);
			Len.push_back(i);
		}
		
	}
	int cnt=1;
	int idx=0;
	// 문제에 주어진 칸의 번호와 좌표를 매핑시키는 Index배열, m[칸의 번호]={칸의 y좌표, 칸의 x좌표}를 나타내는 map 생성	
	while(cnt<N*N){
		int curLen=Len[idx];
		
		while(curLen){
			curY+=dy[dIdx[idx%4]];
			curX+=dx[dIdx[idx%4]];
		
			Index[curY][curX]=cnt;
			m[cnt]={curY,curX};
			++cnt;
					
			--curLen;
		}
		++idx;
		
		
		
	}
	
}

void solve(){
	int y=N/2;
	int x=N/2;
	int aCnt=0,bCnt=0,cCnt=0;
	for(int i=0;i<M;++i){
		int curDir=d[i];
		int curDist=s[i];
		vector<pair<int,int>> deleted;
		//얼음 파편이 떨어져 삭제될 칸들 저장
		for(int j=1;j<=curDist;++j){
			int ny=y+dy[curDir]*j;
			int nx=x+dx[curDir]*j;
			if(isRange(ny,nx)){
				deleted.push_back({ny,nx});
			}
		}
		
		//삭제될 칸들을 기준으로 삭제될 인덱스 다음 값들로 덮어쓰기
		int cnt=0;
		for(int j=0;j<deleted.size();++j){
			int curIdx=Index[deleted[j].first][deleted[j].second];
			curIdx-=cnt;
			
			int nextIdx=curIdx+1;
			while(nextIdx<N*N){
				int cy=m[curIdx].first;
				int cx=m[curIdx].second;
				
				int ny=m[nextIdx].first;
				int nx=m[nextIdx].second;
				board[cy][cx]=board[ny][nx];
				board[ny][nx]=0;
				++curIdx;
				++nextIdx;
			}
			++cnt;
		}
		// 폭발
		bool canBomb=0;
		vector<pair<int,int>> cv;
		while(1){
			bool canBomb=0;
			int conSeq=0;
			int preNum=0;
			vector<pair<pair<int,int>,int>> v;
			//board 전체를 보고, 현재 폭발 할 수 있는(v 벡터의 크기가 4이상) 좌표들을 cv벡터에 저장한다. v벡터는 폭발 유무를 계속 
			//판단해야 하므로 한 번 폭발 이후에는 clear해준다.
			for(int j=1;j<N*N;++j){
				int cy=m[j].first;
				int cx=m[j].second;
				int curNum=board[cy][cx];
				if(curNum==0) continue;
				
				if(v.empty()){
					v.push_back({{cy,cx},j});
				}else{
					if(board[v[v.size()-1].first.first][v[v.size()-1].first.second]==curNum){
						
						v.push_back({{cy,cx},j});
					}else{
						
						if(v.size()>=4){
							canBomb=1;
							int cur_board_num=board[v[0].first.first][v[0].first.second];
							if(cur_board_num==1){
								aCnt+=v.size();
							}else if(cur_board_num==2){
								bCnt+=v.size();
							}else{
								cCnt+=v.size();
							}
							
							for(int k=0;k<v.size();++k){
								
								int ky=v[k].first.first;
								int kx=v[k].first.second;
								int kj=v[k].second;
								cv.push_back({ky,kx});
								board[ky][kx]=0;
								
							}
							
							
						}
						v.clear();
						v.push_back({{cy,cx},j});
					}
					
				}
			}
			// 무언가 변화가 일어나지 않았는데 v의 크기가 4이상인 경우(v의 크기가 4이상이지만 그 후 인덱스의 값들이 모두 0인경우)의 예외처리를 해준다.
			if(!canBomb){
				if(v.size()>=4){
					int last_num=board[v[0].first.first][v[0].first.second];
					if(last_num==1){
						aCnt+=v.size();
					}else if(last_num==2){
						bCnt+=v.size();
					}else if(last_num==3){
						cCnt+=v.size();
					}
					for(int t=0;t<v.size();++t){
						int vy=v[t].first.first;
						int vx=v[t].first.second;
						board[vy][vx]=0;
					}
				}
				break;
			}
		}
		// 현재 상태에서 일어날 수 있는 폭발 모두 완료, 폭발이 일어난 곳은 0으로 채워짐
		// 폭발이 일어나서 0이된 좌표를 0이 아닌 좌표를 끌어와서 채워준다.
		int curIdx=1;
		int cIdx=0;
		int to_add=-1;
		bool flag=0;
		while(curIdx<N*N){
			if(to_add>0){
				if(curIdx+to_add>=N*N){
					break;
				}
			}
			int cy=m[curIdx].first;
			int cx=m[curIdx].second;
			if(board[cy][cx]==0){
				if(to_add==-1){
					to_add=1;
					while(curIdx+to_add<N*N){
						int ny=m[curIdx+to_add].first;
						int nx=m[curIdx+to_add].second;
						if(board[ny][nx]!=0){
							break;
						}else{
							++to_add;
						}
						if(curIdx+to_add==N*(N-1)){
							flag=1;
						}
					}
					if(flag==1){
						break;
					}
				}else{
					int ny=m[curIdx+to_add].first;
					int nx=m[curIdx+to_add].second;
					if(board[ny][nx]==0){
						++to_add;
					}else{
						board[cy][cx]=board[ny][nx];
						board[ny][nx]=0;
						++curIdx;
					}
				}
			}else{
				to_add=-1;
				++curIdx;
			}
		}
		
		// 폭발 후 0이 된 좌표 0이 아닌 값들로 채우기 완료, 연속하는 구슬들을 그룹으로 해서 board를 채우면 끝!
		// tmp[idx]에 board[Index[idx].first][Index[idx].second]에 넣어질 값들을 저장한다.
		curIdx=1;
		vector<int> tmp;
		tmp.push_back(0);
		while(curIdx<N*N){
			int cy=m[curIdx].first;
			int cx=m[curIdx].second;
			if(board[cy][cx]==0) break;
			if(curIdx==(N*N)-1){
				tmp.push_back(board[cy][cx]);
				break;
			}
			
			int ny=m[curIdx+1].first;
			int nx=m[curIdx+1].second;
			bool flag=0;
			if(curIdx+2<N*N){
				int nny=m[curIdx+2].first;
				int nnx=m[curIdx+2].second;
				if(board[cy][cx]==board[ny][nx] && board[ny][nx]==board[nny][nnx]){
					tmp.push_back(3);
					tmp.push_back(board[cy][cx]);
					curIdx+=3;
					flag=1;
				}
			}
			if(flag==0){
				if(board[cy][cx]==board[ny][nx]){
					tmp.push_back(2);
					tmp.push_back(board[cy][cx]);
					curIdx+=2;
				}else{
					tmp.push_back(1);
					tmp.push_back(board[cy][cx]);
					curIdx+=1;
				}
			}
			
		}
		
		curIdx=1;
		while(curIdx<N*N && curIdx<tmp.size()){
			int cy=m[curIdx].first;
			int cx=m[curIdx].second;
			board[cy][cx]=tmp[curIdx];
			++curIdx;
		}
		// 나머지 부분들은 0으로 채워준다.
		while(curIdx<N*N){
			int cy=m[curIdx].first;
			int cx=m[curIdx].second;
			board[cy][cx]=0;
			++curIdx;
		}
		
	}
	cout<<aCnt+2*bCnt+3*cCnt<<endl;
}


int main() {
	// your code goes here
	Input();
	index_set();
	solve();
	return 0;
}