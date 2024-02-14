#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
using namespace std;


int N,M;
const int MAX=20+1;
int board[MAX][MAX];
vector<pair<int,int>> pos;
int ps;
void Input(){
	cin>>N>>M;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			cin>>board[i][j];
			if(board[i][j]==0){
				pos.push_back({i,j});
			}
		}
	}
	ps=pos.size();
}
vector<int> picked;
int cnt=0;
bool visited[400+1];
bool check[MAX][MAX];
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<N && x<M);
}
int BFS(int cy, int cx){
	queue<pair<int,int>> q;
	q.push({cy,cx});
	check[cy][cx]=1;
	// cout<<cy<<" "<<cx<<endl;
	int cur_cnt=1;
	bool flag=0;
	while(!q.empty()){
		int y=q.front().first;
		int x=q.front().second;
		q.pop();
		for(int i=0;i<4;++i){
			int ny=y+dy[i];
			int nx=x+dx[i];
			if(!isRange(ny,nx)) continue;
			if(check[ny][nx]) continue;
			if(board[ny][nx]==2){

				check[ny][nx]=1;
				q.push({ny,nx});
				++cur_cnt;
			}else if(board[ny][nx]==0){
				flag=1;
			}
		}
	}
	if(flag){
		return 0;
	}else{
		return cur_cnt;	
	}
	
}
int calc(){
	int cur_cnt=0;
	for(int i=0;i<picked.size();++i){
		int y=pos[picked[i]].first;
		int x=pos[picked[i]].second;
		board[y][x]=1;
	}
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			check[i][j]=0;
		}
	}
	// cout<<"before"<<endl;
	// for(int i=0;i<N;++i){
	// 	for(int j=0;j<M;++j){
	// 		cout<<board[i][j];
	// 	}cout<<endl;
	// }cout<<endl;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			if(!check[i][j] && board[i][j]==2){
				bool flag=0;
				for(int k=0;k<4;++k){
					int ny=i+dy[k];
					int nx=j+dx[k];
					if(!isRange(ny,nx)) continue;
					if(board[ny][nx]==0){
						// if(i==3 && j==1){
						// 	cout<<"he";
						// }
						flag=1;
						break;
					}
				}
				if(flag) continue;
				// cout<<flag<<" "<<i<<" "<<j<<endl;
				cur_cnt+=BFS(i,j);
			}
		}
	}
	for(int i=0;i<picked.size();++i){
		int y=pos[picked[i]].first;
		int x=pos[picked[i]].second;
		board[y][x]=0;
	}
	// cout<<"after"<<endl;
	// for(int i=0;i<N;++i){
	// 	for(int j=0;j<M;++j){
	// 		cout<<board[i][j];
	// 	}cout<<endl;
	// }
	// cout<<endl;
	return cur_cnt;
}
void pick(int idx){
	if(picked.size()==2){
		cnt=max(cnt, calc());
		return;
	}
	for(int i=idx;i<ps;++i){
		if(!visited[i]){
			visited[i]=1;
			picked.push_back(i);
			pick(i+1);
			picked.pop_back();
			visited[i]=0;
		}
	}
}
void solve(){
	pick(0);
	cout<<cnt;
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