#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;


int H,W;
const int MAX=500+1;
string board[MAX];
pair<int,int> start, finish;
int dist[MAX][MAX];
int INF=1222232421;
void Input(){
	cin>>W>>H;
	for(int i=0;i<H;++i){
		cin>>board[i];
		for(int j=0;j<W;++j){
			if(board[i][j]=='T'){
				start.first=i;
				start.second=j;
			}else if(board[i][j]=='E'){
				finish.first=i;
				finish.second=j;
			}
			dist[i][j]=INF;
		}
	}
}
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<H && x<W);
}

int dijkstra(){
	priority_queue<pair<int,pair<int,int>>> pq;
	pq.push({0,start});
	dist[start.first][start.second]=0;
	while(!pq.empty()){
		int cur_dist=pq.top().first*-1;
		int y=pq.top().second.first;
		int x=pq.top().second.second;
		// cout<<y<<" "<<x<<" "<<cur_dist<<endl;
		if(y==finish.first && x==finish.second){
			return cur_dist;
		}
		pq.pop();
		for(int i=0;i<4;++i){
			int ny=y+dy[i];
			int nx=x+dx[i];
			if(!isRange(ny,nx)) continue;
			if(board[ny][nx]=='R' || board[ny][nx]=='H' || board[ny][nx]=='T') continue;
			if(board[ny][nx]=='E'){
				pq.push({cur_dist*-1,{ny,nx}});
			}else{
				// cout<<ny<<" "<<nx<<endl;
				bool flag=0;
				int next_dist=cur_dist+(board[ny][nx]-'0');
				while(1){
					ny+=dy[i];
					nx+=dx[i];
					if(!isRange(ny,nx)|| board[ny][nx]=='H' || board[ny][nx]=='T'){
						flag=1;
						// cout<<"HEHEHE "<<ny<<" "<<nx<<endl;
						break;
					}
					// cout<<ny<<" "<<nx<<endl;
					if(board[ny][nx]=='E'){
						// cout<<next_dist<<endl;
						break;
					}else if(board[ny][nx]=='R'){
						ny-=dy[i];
						nx-=dx[i];
						break;
					}else{
						next_dist+=(board[ny][nx]-'0');
					}
				}
				// cout<<"nd "<<ny<<" "<<nx<<" "<<next_dist<<endl;
				if(!flag){
					if(dist[ny][nx]>next_dist){
						dist[ny][nx]=next_dist;
						pq.push({next_dist*-1,{ny,nx}});	
					}
					
				}
			}

		}
	}
	return -1;
}

void solve(){
	cout<<dijkstra();
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