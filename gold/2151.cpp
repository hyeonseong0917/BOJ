#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define ll long long

int N;
string board[50+1];
vector<pair<int,int>> mirror;

int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
bool mirror_check[2500+1];
bool is_mirror[50+1][50+1];
bool visited[50+1][50+1][4+1];
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<N && x<N);
}
vector<int> tmp_mirror;
int cy=-1,cx=-1,dir=-1,fy,fx;
bool flag=0;
void dfs(int y, int x, int d){
	// cout<<y<<" "<<x<<" "<<d<<endl;
	// cout<<is_mirror[y][x]<<endl;
	if(y==fy && x==fx){
		flag=1;
		return;
	}
	if(flag) return;
	int ny=y+dy[d];
	int nx=x+dx[d];
	if(!isRange(ny,nx) || board[ny][nx]=='*'){
		return;
	}
	
	if(is_mirror[ny][nx]){
		if(!visited[ny][nx][(d+1)%4]){
			visited[ny][nx][(d+1)%4]=1;
			dfs(ny,nx,(d+1)%4);
		}
		if(!visited[ny][nx][(d+3)%4]){
			visited[ny][nx][(d+3)%4]=1;
			dfs(ny,nx,(d+3)%4);
		}
	}else{
		if(!visited[ny][nx][d]){
			visited[ny][nx][d]=1;
			dfs(ny,nx,d);
		}
	}

}
void mirror_install(int cur_num){
	if(cur_num==0){
		// 다 설치했음
		// tmp_mirror에 번호가 들어가 있음
		// tmp_mirror의 방향은 어떡할건지?
		// 현재 방향에 대해 +1 or +3
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j){
				is_mirror[i][j]=0;
			}
		}
		if(!tmp_mirror.empty()){
			for(int i=0;i<tmp_mirror.size();++i){
				int y=mirror[tmp_mirror[i]].first;
				int x=mirror[tmp_mirror[i]].second;
				is_mirror[y][x]=1;
			}	
		}
		
		for(int i=0;i<4;++i){
			if(!visited[cy][cx][i]){
				visited[cy][cx][i]=1;
				dfs(cy,cx,i);	
			}
			
		}
		return;
	}
	for(int i=0;i<mirror.size();++i){
		if(!mirror_check[i]){
			mirror_check[i]=1;
			tmp_mirror.push_back(i);
			mirror_install(cur_num-1);
			tmp_mirror.pop_back();
			mirror_check[i]=0;
		}
	}
}
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=1;
	while(t--){
		cin>>N;
		int ans=-1;
		for(int i=0;i<N;++i){
			cin>>board[i];
			for(int j=0;j<N;++j){
				if(board[i][j]=='!'){
					mirror.push_back({i,j});
				}
				if(board[i][j]=='#'){
					if(cy==-1){
						cy=i;
						cx=j;
					}else{
						fy=i;
						fx=j;
					}
				}
			}
		}
		for(int i=0;i<=mirror.size();++i){
			// i개만큼 거울을 설치
			for(int j=0;j<mirror.size();++j){
				mirror_check[j]=0;
			}
			tmp_mirror.clear();
			for(int j=0;j<N;++j){
				for(int k=0;k<N;++k){
					for(int p=0;p<4;++p){
						visited[j][k][p]=0;
					}
				}
			}
			mirror_install(i);
			if(flag){
				ans=i;
				break;
			}
		}
		cout<<ans;
	}

	return 0;
}