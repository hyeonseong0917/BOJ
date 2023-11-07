#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long


int N,M,T,D;
const int MAX=25+1;
int board[MAX][MAX];
int dist[MAX][MAX]; // 0,0에서 y,x까지의 최단거리
int home[MAX][MAX]; // y,x에서 0,0까지의 최단거리
int INF=122232421;
void Input(){
	cin>>N>>M>>T>>D;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			char c;
			cin>>c;
			if(c>='A' && c<='Z'){
				board[i][j]=c-'A';
			}else{
				board[i][j]=c-'a'+26;
			}
			dist[i][j]=INF;
			home[i][j]=INF;
		}
	}
	dist[0][0]=0;
	home[0][0]=0;
}
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int tmp_home[MAX][MAX];
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<N && x<M);
}
void dikjstra(int y, int x, bool is_dist){
	priority_queue<pair<int,pair<int,int>>> pq;
	pq.push({0,{y,x}});
	if(is_dist){
		// 0,0에서 y,x까지
		dist[y][x]=0;
		while(!pq.empty()){
			int cur_dist=pq.top().first*-1; 
			int cy=pq.top().second.first;
			int cx=pq.top().second.second;
			pq.pop();
			for(int i=0;i<4;++i){
				int ny=cy+dy[i];
				int nx=cx+dx[i];
				int diff=abs(board[ny][nx]-board[cy][cx]);
				if(!isRange(ny,nx)) continue;
				if(diff>T) continue;
				if(board[cy][cx]<board[ny][nx]){
					if(dist[ny][nx]>cur_dist+diff*diff){
						dist[ny][nx]=cur_dist+diff*diff;
						pq.push({dist[ny][nx]*-1,{ny,nx}});
					}
				}else{
					if(dist[ny][nx]>cur_dist+1){
						dist[ny][nx]=cur_dist+1;
						pq.push({dist[ny][nx]*-1,{ny,nx}});
					}
				}
			}
		}
	}else{
		// y,x에서 0,0까지 가야함
		for(int i=0;i<N;++i){
			for(int j=0;j<M;++j){
				tmp_home[i][j]=INF;
			}
		}
		tmp_home[y][x]=0;
		int cur_num=0;
		while(!pq.empty()){
			int cur_dist=pq.top().first*-1;
			int cy=pq.top().second.first;
			int cx=pq.top().second.second;
			if(cy==0 && cx==0){
				home[y][x]=cur_dist;
				return;
			}
			pq.pop();
			for(int i=0;i<4;++i){
				int ny=cy+dy[i];
				int nx=cx+dx[i];
				int diff=abs(board[ny][nx]-board[cy][cx]);
				if(!isRange(ny,nx)) continue;
				if(diff>T) continue;
				if(board[cy][cx]<board[ny][nx]){
					if(tmp_home[ny][nx]>cur_dist+diff*diff){
						tmp_home[ny][nx]=cur_dist+diff*diff;
						pq.push({tmp_home[ny][nx]*-1,{ny,nx}});
					}
				}else{
					if(tmp_home[ny][nx]>cur_dist+1){
						tmp_home[ny][nx]=cur_dist+1;
						pq.push({tmp_home[ny][nx]*-1,{ny,nx}});
					}
				}
			}
		}

		return;
	}
}
void solve(){
	dikjstra(0,0,1);
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			dikjstra(i,j,0);
		}
	}
	int ans=0;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			if(dist[i][j]+home[i][j]<=D){
				ans=max(ans,board[i][j]);
			}
			
		}
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