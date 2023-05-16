#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX=1557;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int dist[MAX][MAX]={0,};
int R,C=0;
char board[MAX][MAX];
vector<pair<int,int>> v;
pair<int,int> swan,next_swan;
int idx=0;
int day=0;

bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<R &&x<C);
}
void Input(){
	cin>>R>>C;
	for(int i=0;i<R;++i){
		for(int j=0;j<C;++j){
			cin>>board[i][j];
			if(board[i][j]=='L'){
				swan={i,j};
			}
		}
	}
	
}
bool visited[MAX][MAX]={0,};
queue<pair<int,int>> next_wq;
void MELT(){
	for(int i=0;i<MAX;++i){
		for(int j=0;j<MAX;++j){
			visited[i][j]=0;
		}
	}
	queue<pair<int,int>> cur_wq;
	cur_wq=next_wq;
	next_wq = queue<pair<int,int>>();

	while(!cur_wq.empty()){
		int y=cur_wq.front().first;
		int x=cur_wq.front().second;
		cur_wq.pop();
		board[y][x]='.';
		for(int i=0;i<4;++i){
			int ny=y+dy[i];
			int nx=x+dx[i];
			if(isRange(ny,nx) && board[ny][nx]=='X' && !visited[ny][nx]){
				visited[ny][nx]=1;
				next_wq.push({ny,nx});
			}
		}
	}
}

void solve(){
	for(int i=0;i<MAX;++i){
		for(int j=0;j<MAX;++j){
			dist[i][j]=0;
			visited[i][j]=0;
		}
	}
	for(int i=0;i<R;++i){
		for(int j=0;j<C;++j){
			if(board[i][j]=='X'){
				for(int k=0;k<4;++k){
					int ny=i+dy[k];
					int nx=j+dx[k];
					if(isRange(ny,nx) && !visited[i][j] && board[ny][nx]!='X'){
						visited[i][j]=1;
						next_wq.push({i,j});
					}
				}
			}
		}
	}
	queue<pair<int,int>> q,nq;
	nq.push(swan);
	dist[swan.first][swan.second]=1;
	int res=0;	
	bool flag=0;
	bool check[MAX][MAX];
	while(!flag){
		MELT();
		++day;
		
		q=nq;
		nq = queue<pair<int,int>>();
		for(int i=0;i<MAX;++i){
			for(int j=0;j<MAX;++j){
				check[i][j]=0;
			}
		}
		// cout<<day<<endl;
		// for(int i=0;i<R;++i){
		// 	for(int j=0;j<C;++j){
		// 		cout<<board[i][j];
		// 	}cout<<endl;
		// }cout<<endl;
		// if(day==3){
		// 	cout<<q.empty()<<endl;
		// }
		while(!q.empty() && !flag){
			// if(day==3) cout<<"hello";
			int y=q.front().first;
			int x=q.front().second;
			q.pop();
			for(int i=0;i<4;++i){
				int ny=y+dy[i];
				int nx=x+dx[i];
				if(isRange(ny,nx)){
					if(board[ny][nx]!='X' && !dist[ny][nx]){
						q.push({ny,nx});
						dist[ny][nx]=1;
						if(board[ny][nx]=='L'){
							flag=1;
							res=day;
							break;
						}
					}
					if(board[ny][nx]=='X' && !check[ny][nx]){
						// cout<<day<<" "<< ny<<" "<<nx<<endl;
						nq.push({ny,nx});
						check[ny][nx]=1;
					}
				}
			}
		}
		
	}
	cout<<res;
	
	
}

int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}
