#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

int N,M;
const int MAX=10+1;
int board[MAX][MAX];
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
pair<int,int> graph[6+1][6+1]; // graph[i][j]={i에서 j섬까지의 최소 가중치, 이 때의 방향}
int K; // 섬의 개수
vector<pair<pair<int,int>,pair<int,int>>> v;
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<N && x<M);
}
void Input(){
	cin>>N>>M;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			cin>>board[i][j];
		}
	}
	for(int i=1;i<=6;++i){
		for(int j=1;j<=6;++j){
			graph[i][j]={0,0};
		}
	}
}
bool island_check[MAX][MAX];
void island_dfs(int y, int x, int cnt){
	// cout<<y<<" "<<x<<" "<<cnt<<endl;
	for(int i=0;i<4;++i){
		int ny=y+dy[i];
		int nx=x+dx[i];
		if(!isRange(ny,nx)) continue;
		if(island_check[ny][nx]) continue;
		if(board[ny][nx]==1){
			island_check[ny][nx]=1;
			board[ny][nx]=cnt;
			island_dfs(ny,nx,cnt);
		}
	}
}
void island_init(){
	int cnt=1;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			if(board[i][j]!=0 && !island_check[i][j]){
				island_check[i][j]=1;
				board[i][j]=cnt;
				K=cnt;
				island_dfs(i,j,cnt);
				++cnt;
			}
		}
	}
}
void is_connected_set(){
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			if(board[i][j]!=0){
				bool is_zero=0;
				for(int k=0;k<4;++k){
					int ny=i+dy[k];
					int nx=j+dx[k];
					if(!isRange(ny,nx)) continue;
					if(board[ny][nx]==0){
						is_zero=1;
					}
				}
				if(!is_zero) continue;
				int y=i;
				int x=j;
				int cur_num=board[i][j];
				for(int k=0;k<4;++k){
					int cur_dir=k;
					int ny=y+dy[cur_dir];
					int nx=x+dx[cur_dir];
					bool flag=0;
					int cur_cnt=0;
					int next_num=-1;
					while(1){
						if(!isRange(ny,nx) || board[ny][nx]==cur_num){
							break;
						}
						if(board[ny][nx]==0){
							++cur_cnt;
							ny+=dy[cur_dir];
							nx+=dx[cur_dir];
						}else{
							if(cur_cnt>=2){
								next_num=board[ny][nx];
								flag=1;
							}
							break;
						}
					}
					// cout<<i<<" "<<j<<" "<<flag<<endl;
					if(flag){
						// cout<<i<<" "<<j<<" "<<ny<<" "<<nx<<endl;	
						if(graph[cur_num][next_num]==make_pair(0,0)){
							// cout<<cur_num<<" "<<next_num<<" "<<cur_cnt<<endl;
							graph[cur_num][next_num]={cur_cnt,cur_dir};
							graph[next_num][next_num]={cur_cnt,(cur_dir+2)%4};
						}else{
							if(graph[cur_num][next_num].first>cur_cnt){
								graph[cur_num][next_num]={cur_cnt,cur_dir};
								graph[next_num][cur_num]={cur_cnt,(cur_dir+2)%4};
							}
						}
					}
				}
			}
		}
	}
	// i번 섬과 j번 섬은 first만큼의 가중치를 second방향으로 가지면서 이루어져 있음 (i<j)
	for(int i=1;i<=K;++i){
		for(int j=i+1;j<=K;++j){
			if(graph[i][j].first>=2){
				v.push_back({{i,j},{graph[i][j].first, graph[i][j].second}});
			}
		}
	}
}
vector<int> picked;
bool visited[36+1];
int ans=122232421;
vector<pair<int,int>> p[6+1];
bool check[6+1];
int dist=0;

void traverse(int cur_num){
	for(int i=0;i<p[cur_num].size();++i){
		int next_num=p[cur_num][i].first;
		int next_dist=p[cur_num][i].second;
		if(!check[next_num]){
			check[next_num]=1;
			dist+=next_dist;
			traverse(next_num);
		}
	}
}
void dfs(){
	
	if(picked.size()==K-1){
		dist=0;		
		for(int i=0;i<7;++i){
			p[i].clear();
			check[i]=0;
		}
		for(int i=0;i<picked.size();++i){
			int cur_idx=picked[i];
			int cur_num=v[cur_idx].first.first;
			int next_num=v[cur_idx].first.second;
			int cur_dist=v[cur_idx].second.first;
			p[cur_num].push_back({next_num,cur_dist});
			p[next_num].push_back({cur_num,cur_dist});
		}
		check[1]=1;
		traverse(1);

		bool flag=0;
		for(int i=1;i<=K;++i){
			if(!check[i]) flag=1;
		}
		if(!flag){
			ans=min(ans,dist);
		}
		return;
	}
	for(int i=0;i<v.size();++i){
		if(!visited[i]){
			visited[i]=1;
			picked.push_back(i);
			dfs();
			visited[i]=0;
			picked.pop_back();
		}
	}
}


void solve(){
	island_init();
	// cout<<endl;
	// for(int i=0;i<N;++i){
	// 	for(int j=0;j<M;++j){
	// 		cout<<board[i][j]<<" ";
	// 	}cout<<endl;
	// }
	is_connected_set();
	// for(int i=1;i<=K;++i){
	// 	for(int j=i+1;j<=K;++j){
	// 		cout<<i<<" "<<j<<" "<<graph[i][j].first<<" "<<graph[i][j].second<<endl;
	// 	}
	// }
	dfs();
	if(ans==122232421){
		ans=-1;
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