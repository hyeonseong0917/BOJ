#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

int N,M;
const int MAX=4+1;
string board[MAX];
bool visited[MAX][MAX];
int dy[2]={0,1};
int dx[2]={1,0};
void Input(){
	cin>>N>>M;
	for(int i=0;i<N;++i){
		cin>>board[i];
	}
}
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<N && x<M);
}
int ans=0;
void dfs(int y, int x, int sum){
	if(y==N-1 && x==M-1){
		if(!visited[y][x]){
			sum+=board[y][x]-'0';
		}
		ans=max(ans,sum);
		return;
	}
	if(y==N && x==0){
		ans=max(ans,sum);
		return;	
	}
	if(visited[y][x]){
		if(!isRange(y,x+1)){
			dfs(y+1,0,sum);
		}else{
			dfs(y,x+1,sum);
		}
	}else{
		string cur_num="";
		int idx=4;
		for(int i=1;i<=4;++i){
			int ny=y+dy[0]*(i-1);
			int nx=x+dx[0]*(i-1);
			if(!isRange(ny,nx) || visited[ny][nx]){
				idx=i-1;
				break;	
			} 
			cur_num+=board[ny][nx];
			visited[ny][nx]=1;
			if(!isRange(y,x+1)){
				dfs(y+1,0,sum+stoi(cur_num));
			}else{
				dfs(y,x+1,sum+stoi(cur_num));
			}
		}	
		for(int j=1;j<=idx;++j){
			int cy=y+dy[0]*(j-1);
			int cx=x+dx[0]*(j-1);
			visited[cy][cx]=0;
		}

		idx=4;
		cur_num="";
		for(int i=1;i<=4;++i){
			int ny=y+dy[1]*(i-1);
			int nx=x+dx[1]*(i-1);
			// cout<<y<<" "<<x<<" "<<ny<<" "<<nx<<" "<<sum<<" "<<cur_num<<endl;
			if(!isRange(ny,nx) || visited[ny][nx]){
				idx=i-1;
				break;	
			} 
			cur_num+=board[ny][nx];
			visited[ny][nx]=1;

			if(!isRange(y,x+1)){
				dfs(y+1,0,sum+stoi(cur_num));
			}else{
				dfs(y,x+1,sum+stoi(cur_num));
			}
		}
		for(int j=1;j<=idx;++j){
			int cy=y+dy[1]*(j-1);
			int cx=x+dx[1]*(j-1);
			visited[cy][cx]=0;
		}
	}
	
}

void solve(){
	dfs(0,0,0);
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