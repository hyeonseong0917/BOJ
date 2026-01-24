#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define ll long long

// 1256
int ans=0;
int n,m,K;
int board[50+1][50+1];
int tmp_board[50+1][50+1];
int copy_board[50+1][50+1];
bool visited[6+1];
vector<pair<int,pair<int,int>>> v;
// order는 크기가 k임. [0,k-1]의 수로 이루어져 있음
vector<int> order;

bool isRange(int y, int x,int ly, int lx, int ny, int nx){
	return (y>=ly && x>=lx && y<=ny && x<=nx);
}
int a=0;
void dfs(){
	int order_size=order.size();
	if(order_size==K){
		// order순으로 배열을 돌려야함
		// for(int i=0;i<k;++i){
		// 	cout<<order[i]<<" ";
		// }cout<<"\n";
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				tmp_board[i][j]=board[i][j];
				copy_board[i][j]=board[i][j];
			}
		}
		for(int i=0;i<K;++i){
			int cur_order=order[i];
			// cur_order번째 명령어를 수행
			int y=v[cur_order].first-1;
			int x=v[cur_order].second.first-1;
			int z=v[cur_order].second.second;

			int ly=y-z;
			int lx=x-z;
			int ry=y+z;
			int rx=x+z;
			// [ly,lx]에서 [ry,rx]까지를 회전함
			bool check[n][m];
			for(int j=0;j<n;++j){
				for(int k=0;k<m;++k){
					check[j][k]=0;
					tmp_board[j][k]=board[j][k];
				}
			}
			int sy=ly;
			int sx=lx;
			
			while(!check[sy][sx]){
				int ty=sy;
				int tx=sx+1;
				if(check[ty][tx]) break;
				// check[ty][tx]=1;
				// 1. ------>
				// if(!a){
				// 	cout<<i<<" "<<ty<<" "<<tx<<" "<<tx<<endl;
				// }
				while(1){
					if(!isRange(ty,tx,ly,lx,ry,rx) || check[ty][tx]){
						--tx;
						++ty;
						break;
					}
					check[ty][tx]=1;
					tmp_board[ty][tx]=board[ty][tx-1];
					++tx;
				}
				// 2. |||||v
				while(1){
					if(!isRange(ty,tx,ly,lx,ry,rx) || check[ty][tx]){
						--tx;
						--ty;
						break;
					}
					check[ty][tx]=1;
					tmp_board[ty][tx]=board[ty-1][tx];
					++ty;
				}
				// 3. <-----
				while(1){
					if(!isRange(ty,tx,ly,lx,ry,rx) || check[ty][tx]){
						++tx;
						--ty;
						break;
					}
					check[ty][tx]=1;
					tmp_board[ty][tx]=board[ty][tx+1];
					--tx;
				}
				// if(!a){
				// 	++a;
				// 	cout<<ty<<" "<<tx<<endl;
				// }

				// 4. |||^
				while(1){
					if(!isRange(ty,tx,ly,lx,ry,rx) || check[ty][tx]){
						break;
					}
					check[ty][tx]=1;
					tmp_board[ty][tx]=board[ty+1][tx];
					--ty;
				}
				
				++sy;
				++sx;
			}
			for(int j=0;j<n;++j){
				for(int k=0;k<m;++k){
					board[j][k]=tmp_board[j][k];
				}
			}
			// if(!a){
			// 	// ++a;
			// 	cout<<i<<"\n";
			// 	for(int j=0;j<n;++j){
			// 		for(int k=0;k<m;++k){
			// 			cout<<tmp_board[j][k]<<" ";
			// 		}cout<<"\n";
			// 	}cout<<"\n";
			// }
			
		}
		// if(a==0){
		// 	// cout<<order[0]<<" "<<order[1]<<"\n";
		// 	++a;
		// 	for(int i=0;i<n;++i){
		// 		for(int j=0;j<m;++j){
		// 			cout<<tmp_board[i][j]<<" ";
		// 		}cout<<"\n";
		// 	}
		// }
		int sum=50*100;
		for(int i=0;i<n;++i){
			int tmp_sum=0;
			for(int j=0;j<m;++j){
				tmp_sum+=tmp_board[i][j];
			}
			sum=min(sum,tmp_sum);
		}
		ans=min(ans,sum);
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				board[i][j]=copy_board[i][j];
			}
		}
		return;
	}
	for(int i=0;i<K;++i){
		if(!visited[i]){
			visited[i]=1;
			order.push_back(i);
			dfs();
			visited[i]=0;
			order.pop_back();
		}
	}
}
void Input(){
	cin>>n>>m>>K;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			cin>>board[i][j];
		}
	}
	for(int i=0;i<K;++i){
		int a,b,c;
		cin>>a>>b>>c;
		v.push_back({a,{b,c}});
	}
}
void Init(){
	ans=100*50;
	for(int i=0;i<=50;++i){
		for(int j=0;j<=50;++j){
			board[i][j]=0;
		}
	}
	for(int i=0;i<=6;++i){
		visited[i]=0;
	}
}
void Solve(){
	dfs();
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	for(ll o=1;o<=1;++o){
		Init();
		Input();
		Solve();
		cout<<ans;
	}
	return 0;
}