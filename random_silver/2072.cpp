#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long

int N;
const int MAX=20+1;
int board[MAX][MAX];
bool visited[MAX][MAX][4+1];
int dy[4]={0,1,1,1};
int dx[4]={1,1,0,-1};
bool isRange(int y, int x){
	return(y>=0 && x>=0 && y<20 && x<20);
}
vector<pair<int,int>> v;
int flag=0;
void Input(){
	cin>>N;
	for(int i=0;i<N;++i){
		int a,b;
		cin>>a>>b;
		v.push_back({a,b});
	}
}
int cnt=1;
void dfs(int y, int x, int dir){
	int ny=y+dy[dir];
	int nx=x+dx[dir];
	if(!isRange(ny,nx) || board[ny][nx]!=board[y][x]){
		return;
	}
	++cnt;
	visited[ny][nx][dir]=1;
	dfs(ny,nx,dir);
}
// 흑: 1, 백: -1
void solve(){
	int ans=-1;
	for(int i=0;i<v.size();++i){
		int y=v[i].first;
		int x=v[i].second;
		if(i%2==0){
			board[y][x]=1;
		}else{
			board[y][x]=-1;
		}
		for(int j=0;j<20;++j){
			for(int k=0;k<20;++k){
				for(int m=0;m<4;++m){
					visited[j][k][m]=0;
				}
			}
		}
		for(int j=0;j<20;++j){
			for(int k=0;k<20;++k){
				for(int m=0;m<4;++m){
					cnt=1;
					if(!visited[j][k][m] && board[j][k]!=0){
						visited[j][k][m]=1;
						dfs(j,k,m);
					}
					if(cnt==5){
						// cout<<j<<" "<<k<<" "<<m<<endl;
						flag=1;
					}
				}
			}
		}
		
		if(flag){
			ans=i+1;
			break;
		}
	}
	cout<<ans;
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	Input();
	solve();
	return 0;
}