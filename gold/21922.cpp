#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define ll long long

int n,m;
const int MAX=2000+1;
int board[MAX][MAX];
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
bool visited[MAX][MAX][4+1];
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<n && x<m);
}
void Input(){
	cin>>n>>m;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			cin>>board[i][j];
		}
	}
}
void solve(){
	queue<pair<pair<int,int>,int>> q;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(board[i][j]==9){
				for(int k=0;k<4;++k){
					q.push({{i,j},k});
					visited[i][j][k]=1;
				}
			}
		}
	}
	// cout<<q.size();
	while(!q.empty()){
		int y=q.front().first.first;
		int x=q.front().first.second;
		int dir=q.front().second;
		// cout<<y<<" "<<x<<" "<<dir<<endl;
		q.pop();
		int ny=y+dy[dir];
		int nx=x+dx[dir];
		if(!isRange(ny,nx)) continue;
		if(visited[ny][nx][dir]) continue;
		visited[ny][nx][dir]=1;
		if(board[ny][nx]==0){
				q.push({{ny,nx},dir});
		}else if(board[ny][nx]==1){
			if(dir==0 || dir==2){
				q.push({{ny,nx},dir});
			}
		}else if(board[ny][nx]==2){
			if(dir==1 || dir==3){
				q.push({{ny,nx},dir});
			}
		}else if(board[ny][nx]==3){
			if(dir==0){
				q.push({{ny,nx},1});
			}else if(dir==1){
				q.push({{ny,nx},0});
			}else if(dir==2){
				q.push({{ny,nx},3});
			}else{
				q.push({{ny,nx},2});
			}
		}else if(board[ny][nx]==4){
			if(dir==0){
				q.push({{ny,nx},3});
			}else if(dir==1){
				q.push({{ny,nx},2});
			}else if(dir==2){
				q.push({{ny,nx},1});
			}else{
				q.push({{ny,nx},0});
			}
		}
	}
	int ans=0;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			for(int k=0;k<4;++k){
				if(visited[i][j][k]){
					++ans;
					break;
				}
			}
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