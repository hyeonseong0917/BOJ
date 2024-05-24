#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define ll long long

const int MAX=50+1;
pair<int,int> dist[MAX][MAX]; // 지나온 쓰레기 개수, 지나오면서 만난 쓰레기 개수
string board[MAX];
int N,M;
pair<int,int> start_pos, fin_pos;
int INF=1222232421;
void Input(){
	cin>>N>>M;
	for(int i=0;i<N;++i){
		cin>>board[i];
		for(int j=0;j<M;++j){
			if(board[i][j]=='S'){
				start_pos.first=i;
				start_pos.second=j;
			}
			if(board[i][j]=='F'){
				fin_pos.first=i;
				fin_pos.second=j;
			}
			dist[i][j]={INF,INF};
		}
	}
}
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<N && x<M);
}
void BFS(){
	queue<pair<pair<int,int>,pair<int,int>>> q; // {{y,x},{지나온 쓰레기 개수, 지나오면서 만난 쓰레기 개수}}
	q.push({start_pos,{0,0}});
	dist[start_pos.first][start_pos.second]={0,0};
	while(!q.empty()){
		int y=q.front().first.first;
		int x=q.front().first.second;
		int get_trash=q.front().second.first;
		int meet_trash=q.front().second.second;
		q.pop();
		// cout<<y<<" "<<x<<" "<<get_trash<<" "<<meet_trash<<endl;
		if(y==fin_pos.first && x==fin_pos.second){
			continue;
		}
		// cout<<"he";
		for(int i=0;i<4;++i){
			int ny=y+dy[i];
			int nx=x+dx[i];
			if(!isRange(ny,nx)) continue;
			// ny,nx로 이동하고 싶음
			
			if(board[ny][nx]=='g'){
				// 쓰레기 칸으로 이동하는 경우
				if(dist[ny][nx].first>1+get_trash){
					dist[ny][nx].first=1+get_trash;
					dist[ny][nx].second=meet_trash;
					q.push({{ny,nx},{1+get_trash, meet_trash}});
				}else if(dist[ny][nx].first==1+get_trash){
					if(dist[ny][nx].second>meet_trash){
						dist[ny][nx].second=meet_trash;
						q.push({{ny,nx},{1+get_trash, meet_trash}});
					}
				}
			}else if(board[ny][nx]!='S'){
				// 빈 칸으로 이동
				if(ny==fin_pos.first && nx==fin_pos.second){
					if(dist[ny][nx].first>get_trash){
						dist[ny][nx].first=get_trash;
						dist[ny][nx].second=meet_trash;
						q.push({{ny,nx},{get_trash,meet_trash}});
					}else if(dist[ny][nx].first==get_trash){
						if(dist[ny][nx].second>meet_trash){
							dist[ny][nx].second=meet_trash;
							q.push({{ny,nx},{get_trash,meet_trash}});
						}
					}
					continue;
				}
				int meet_cnt=0;
				for(int j=0;j<4;++j){
					int nny=ny+dy[j];
					int nnx=nx+dx[j];
					if(!isRange(nny,nnx)) continue;
					if(board[nny][nnx]=='g'){
						++meet_cnt;
					}
				}
				if(meet_cnt!=0){
					meet_cnt=1;
				}
				if(dist[ny][nx].first>get_trash){
					dist[ny][nx].first=get_trash;
					dist[ny][nx].second=meet_trash+meet_cnt;
					q.push({{ny,nx},{get_trash, meet_trash+meet_cnt}});
				}else if(dist[ny][nx].first==get_trash){
					if(dist[ny][nx].second>meet_trash+meet_cnt){
						dist[ny][nx].second=meet_trash+meet_cnt;
						q.push({{ny,nx},{get_trash, meet_trash+meet_cnt}});
					}
				}	
			}
			
			
		}
	}
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	Input();
	BFS();
	cout<<dist[fin_pos.first][fin_pos.second].first<<" "<<dist[fin_pos.first][fin_pos.second].second;
	return 0;
}