#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;


int N,M;
const int MAX=50+1;
string s[MAX];
bool flag=0;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
bool visited[MAX][MAX];
void Input(){
	cin>>N>>M;
	for(int i=0;i<N;++i){
		string t;
		cin>>t;
		s[i]=t;
	}
}
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<N && x<M);
}
void dfs(int cy, int cx, int y, int x, int cnt){
	// cout<<y<<" "<<x<<endl;
	if(cnt>=4 && y==cy && x==cx){

		flag=1;
		return;
	}
	for(int i=0;i<4;++i){
		int ny=y+dy[i];
		int nx=x+dx[i];
		if(!isRange(ny,nx)) continue;
		if(visited[ny][nx] && cy==ny && cx==nx && cnt>=4 && s[ny][nx]==s[y][x]){
			dfs(cy,cx,ny,nx,cnt+1);
		}
		if(!visited[ny][nx] && s[ny][nx]==s[y][x]){
			visited[ny][nx]=1;
			dfs(cy,cx,ny,nx,cnt+1);
		}
	}

}
void solve(){
	for(int i=0;i<N;++i){
		if(flag) break;
		for(int j=0;j<M;++j){
			for(int k=0;k<N;++k){
				for(int p=0;p<M;++p){
					visited[k][p]=0;
				}
			}
			visited[i][j]=1;
			dfs(i,j,i,j,1);
			// if(flag){
			// 	cout<<i<<" "<<j<<endl;
			// }
			if(flag) break;
		}
	}
	if(flag){
		cout<<"Yes";
	}else{
		cout<<"No";
	}
}

int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	Input();
	solve();
	
	return 0;
}
