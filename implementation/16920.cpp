#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N,M,P=0;
const int MAX=1000+1;
vector<pair<int,int>> v[10+1];
int player[MAX];
string board[MAX];
bool visited[MAX][MAX];
bool check[MAX][MAX];
int can_move=0;
void Input(){
	cin>>N>>M>>P;
	for(int i=1;i<=P;++i){
		cin>>player[i];
	}
	for(int i=0;i<N;++i){
		cin>>board[i];
	}
	
	for(int k=1;k<10;++k){
		for(int i=0;i<N;++i){
			for(int j=0;j<M;++j){
				if(board[i][j]-'0'==k){
					v[k].push_back({i,j});
				}
			}
		}
		// for(int u=0;u<v[k].size();++u){
		// 	cout<<v[k][u].first<<endl;
		// 	cout<<v[k][u].second<<endl;
		// }
	}
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			if(board[i][j]=='.'){
				++can_move;
			}
		}
	}
	
	
}
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
bool isRange(int y,int x){
	return (y>=0 && x>=0 && y<N && x<M);
}
vector<int> is_moved(10+1,0);
queue<pair<int,int>> q[10+1];

// void dfs(int y, int x, int cnt, int pidx){
// 	if(cnt==0 || !can_move){
// 		return;
// 	}
// 	for(int i=0;i<4;++i){
// 		int ny=y+dy[i];
// 		int nx=x+dx[i];
// 		if(isRange(ny,nx) && can_move && !check[ny][nx] && board[ny][nx]=='.'){
// 			if(board[ny][nx]=='.'){
// 				--can_move;
// 			}
// 			is_moved[pidx]=1;
// 			board[ny][nx]=pidx+'0';
// 			check[ny][nx]=1;
// 			if(!visited[ny][nx]){
// 				visited[ny][nx]=1;
// 				q.push({{ny,nx},pidx});
// 			}
			
// 			dfs(ny,nx,cnt-1,pidx);
// 			check[ny][nx]=0;
			
// 		}
// 	}
// 	return;
// }


void BFS(){
	
	for(int k=1;k<=P;++k){
		for(int j=0;j<v[k].size();++j){
			q[k].push(v[k][j]);
			visited[v[k][j].first][v[k][j].second]=1;
		}
	}
	while(1){
		for(int i=1;i<=P;++i){
			int dist=player[i];
			while(!q[i].empty() && dist){
				int qs=q[i].size();
				--dist;
				for(int k=0;k<qs;++k){
					int y=q[i].front().first;
					int x=q[i].front().second;
					q[i].pop();
					for(int j=0;j<4;++j){
						int ny=y+dy[j];
						int nx=x+dx[j];
						if(isRange(ny,nx) && board[ny][nx]=='.'){
							board[ny][nx]=i+'0';
							q[i].push({ny,nx});
						// --dist;
						}
					}
				}
				
				
			}
			
		}
		bool fin=1;
		for(int i=1;i<=P;++i){
			if(!q[i].empty()){
				fin=0;
				break;
			}
		}
		if(fin){
			break;
		}
	}
	// while(!q.empty() && can_move){
	// 	int y=q.front().first.first;
	// 	int x=q.front().first.second;
	// 	int player_idx=q.front().second;
	// 	int player_cnt=player[player_idx];
		
	// 	q.pop();
		
	// 	dfs(y,x,player_cnt,player_idx);	
	// 	for(int i=0;i<N;++i){
	// 	for(int j=0;j<M;++j){
	// 		cout<<board[i][j];
	// 	}cout<<endl;
	// }cout<<endl;
		// for(int i=0;i<4;++i){
		// 	for(int j=1;j<=player_cnt;++j){
				
		// 			int ny=y+dy[i]*j;
		// 			int nx=x+dx[i]*j;
		// 			if(isRange(ny,nx) && !visited[ny][nx] && board[ny][nx]=='.'){
						
		// 				board[ny][nx]=player_idx+'0';
		// 				visited[ny][nx]=1;
		// 				q.push({{ny,nx},player_idx});
		// 			}else{
		// 				break;
		// 			}
		// 		}
		// }
	// }
	return;
}


int main() {
	// your code goes here
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	Input();
	BFS();
	vector<int> ans;
	for(int i=1;i<=P;++i){
		int cnt=0;
		for(int j=0;j<N;++j){
			for(int k=0;k<M;++k){
				if(board[j][k]-'0'==i){
					++cnt;
				}
			}
		}
		ans.push_back(cnt);
	}
	for(int i=0;i<ans.size();++i){
		cout<<ans[i]<<" ";
		
	}
	// cout<<endl;
	// for(int i=0;i<N;++i){
	// 	for(int j=0;j<M;++j){
	// 		cout<<board[i][j];
	// 	}cout<<endl;
	// }
	return 0;
}