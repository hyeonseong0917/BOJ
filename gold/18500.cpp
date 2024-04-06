#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

int N,R,C;
const int MAX=100+1;
char board[MAX][MAX];
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<R && x<C);
}
vector<int> v;
bool visited[MAX][MAX];
void Input(){
	cin>>R>>C;
	for(int i=0;i<R;++i){
		for(int j=0;j<C;++j){
			cin>>board[i][j];
		}
	}
	cin>>N;
	for(int i=0;i<N;++i){
		int a=0;
		cin>>a;
		v.push_back(a);
	}
}
vector<vector<pair<int,int>>> p;
void bfs(int cy, int cx, int idx){
	queue<pair<int,int>> q;
	q.push({cy,cx});
	visited[cy][cx]=1;
	while(!q.empty()){
		int y=q.front().first;
		int x=q.front().second;
		if(idx!=-1){
			p[idx].push_back({y,x});
		}
		q.pop();
		for(int i=0;i<4;++i){
			int ny=y+dy[i];
			int nx=x+dx[i];
			if(!isRange(ny,nx) || visited[ny][nx] || board[ny][nx]=='.') continue;
			visited[ny][nx]=1;
			q.push({ny,nx});
		}
	}
}
bool comp(pair<int,int> a, pair<int,int> b){
	if(a.second==b.second){
		return a.first>b.first;
	}
	return a.second<b.second;
}
bool cmp(pair<int,int> a, pair<int,int> b){
	return a.first>b.first;
}

void solve(){
	for(int i=0;i<v.size();++i){
		int cur_cluster_cnt=0;
		for(int j=0;j<R;++j){
			for(int k=0;k<C;++k){
				visited[j][k]=0;
			}
		}
		for(int j=0;j<R;++j){
			for(int k=0;k<C;++k){
				if(!visited[j][k] && board[j][k]=='x'){
					++cur_cluster_cnt;
					bfs(j,k,-1);
				}
			}
		}
		if(i%2==0){
			for(int j=0;j<C;++j){
				if(board[R-v[i]][j]=='x'){
					board[R-v[i]][j]='.';
					// cout<<"fmeaw"<<" "<<R-v[i]<<" "<<j<<endl;
					break;
				}
			}
		}else{
			for(int j=C-1;j>=0;--j){
				if(board[R-v[i]][j]=='x'){
					board[R-v[i]][j]='.';
					break;
				}
			}
		}
		int next_cluster_cnt=0;
		for(int j=0;j<R;++j){
			for(int k=0;k<C;++k){
				visited[j][k]=0;
			}
		}
		for(int j=0;j<R;++j){
			for(int k=0;k<C;++k){
				if(!visited[j][k] && board[j][k]=='x'){
					++next_cluster_cnt;
					bfs(j,k,-1);
				}
			}
		}
		if(next_cluster_cnt>cur_cluster_cnt){
			// cout<<i<<" "<<next_cluster_cnt<<" "<<cur_cluster_cnt;
			for(int i=0;i<p.size();++i){
				p[i].clear();
			}
			for(int j=0;j<R;++j){
				for(int k=0;k<C;++k){
					visited[j][k]=0;
				}
			}
			int cur_idx=0;
			for(int j=0;j<R;++j){
				for(int k=0;k<C;++k){
					if(!visited[j][k] && board[j][k]=='x'){
						vector<pair<int,int>> tmp;
						tmp.clear();
						p.push_back(tmp);
						bfs(j,k,cur_idx++);
					}
				}
			}
			int move_idx=-1;
			bool check[100+1];
			
			for(int j=0;j<cur_idx;++j){
				vector<pair<int,int>> tmp=p[j];
				sort(tmp.begin(),tmp.end(),comp);
				for(int k=0;k<C;++k){
					check[k]=0;
				}
				bool flag=0;
				for(int k=0;k<tmp.size();++k){
					int y=tmp[k].first;
					int x=tmp[k].second;
					if(check[x]) continue;
					check[x]=1;
					if(!isRange(y+1,x)){
						flag=1;
						break;
					}
					if(board[y+1][x]!='.'){
						flag=1;
						break;
					}
				}
				if(!flag){
					move_idx=j;
					break;
				}
			}
			if(move_idx!=-1){
				// cout<<"he"<<endl;
				int step=122232421;
				bool c_check[100+1][100+1];
				vector<pair<int,int>> tmp=p[move_idx];
				// sort(tmp.begin(),tmp.end(),comp);
				for(int k=0;k<R;++k){
					for(int u=0;u<C;++u){
						c_check[k][u]=0;
					}
				}
				for(int i=0;i<tmp.size();++i){
					int y=tmp[i].first;
					int x=tmp[i].second;
					c_check[y][x]=1;
				}
				for(int i=0;i<tmp.size();++i){
					int y=tmp[i].first;
					int x=tmp[i].second;
					// if(check[x]) continue;
					// check[x]=1;
					// cout<<y<<" "<<x<<endl;
					int ny=y;
					int nx=x;
					int cur_step=0;
					bool c=0;
					while(1){
						ny+=1;
						if(!isRange(ny,nx)) break;
						if(board[ny][nx]=='.'){
							++cur_step;
						}else{
							if(c_check[ny][nx]){
								c=1;
							}
							break;
						}
					}
					if(cur_step!=0 && !c){
						step=min(step,cur_step);
					}
				}	
				sort(tmp.begin(),tmp.end(),cmp);
				// cout<<i<<" "<<step<<endl;
				for(int i=0;i<tmp.size();++i){
					int y=tmp[i].first;
					int x=tmp[i].second;
					// cout<<y<<" "<<x<<endl;
					board[y][x]='.';
					board[y+step][x]='x';
				}
			}
			// for(int j=0;j<R;++j){
			// 	for(int k=0;k<C;++k){
			// 		cout<<board[j][k];
			// 	}cout<<endl;
			// }cout<<endl;
		}
	}
	for(int j=0;j<R;++j){
		for(int k=0;k<C;++k){
			cout<<board[j][k];
		}cout<<"\n";
	}cout<<"\n";
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);	
	Input();
	solve();
	return 0;
}