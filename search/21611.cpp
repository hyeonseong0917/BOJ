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
	// for(int i=0;i<N;++i){
	// 	for(int j=0;j<N;++j){
	// 		cout<<Index[i][j]<<" ";
	// 	}cout<<endl;
	// }
}

void solve(){
	int y=N/2;
	int x=N/2;
	for(int i=0;i<M;++i){
		int curDir=d[i];
		int curDist=s[i];
		vector<pair<int,int>> deleted;
		for(int j=1;j<=curDist;++j){
			int ny=y+dy[curDir]*j;
			int nx=x+dx[curDir]*j;
			if(isRange(ny,nx)){
				board[ny][nx]=0;
				deleted.push_back({ny,nx});
			}
		}
		for(int j=0;j<deleted.size();++j){
			int curIdx=Index[deleted[j].first][deleted[j].second];
			// cout<<curIdx<<endl;
			// cout<<m[4].first<<endl;
			int nextY=m[curIdx+1].first;
			int nextX=m[curIdx+1].second;
			board[deleted[j].first][deleted[j].second]=board[nextY][nextX];
		}
		bool canBomb=0;
		while(1){
			int conSeq=0;
			int preNum=0;
			vector<pair<int,int>> v;
			for(int j=1;j<N*N;++j){
				int cy=m[j].first;
				int cx=m[j].second;
				int curNum=board[cy][cx];
				if(v.empty()){
					v.push_back({cy,cx});
				}else{
					if(board[v[v.size()-1].first][v[v.size()-1].second]==curNum){
						v.push_back(curNum);
						
					}else{
						if(v.size()>=4){
							canBomb=1;
							for(int k=0;k<v.size();++k){
								int ky=v[k].first;
								int kx=v[k].second;
								board[ky][kx]=board[ky+v.size()][kx+v.size()];
								// board[ky+v.size()][kx+v.size()]=-1;
							}		
							
							v.clear();
						}else{
							v.clear();
							v.push_back({cy,cx});
						}
					}
				}
				if(j==N-1 && v.size()>=4){
					canBomb=1;
					if(v.size()>=4){
						for(int k=0;k<v.size();++k){
							int ky=v[k].first;
							int kx=v[k].second;
							board[ky][kx]=board[ky+v.size()][kx+v.size()];
								// board[ky+v.size()][kx+v.size()]=-1;
						}		
							
						v.clear();
					}
				}
			if(!canBomb){
				break;
			}
		}
		
		
		
	}
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cout<<board[i][j]<<" ";
		}cout<<endl;
	}
}

int main() {
	// your code goes here
	Input();
	index_set();
	solve();
	return 0;
}