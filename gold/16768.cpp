#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define ll long long

const int MAX=1000+1;
string board[MAX];
int n,k;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
bool visited[MAX][10+1];

bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<n && x<10);
}
void Input(){
	cin>>n>>k;
	for(int i=0;i<n;++i){
		cin>>board[i];
	}
}
queue<pair<int,int>> pos;
queue<pair<int,int>> tmp;
int bfs(int cy ,int cx){
	char cur_color=board[cy][cx];
	queue<pair<int,int>> q;
	q.push({cy,cx});
	visited[cy][cx]=1;
	tmp.push({cy,cx});
	int cnt=1;
	while(!q.empty()){
		int y=q.front().first;
		int x=q.front().second;
		q.pop();
		for(int i=0;i<4;++i){
			int ny=y+dy[i];
			int nx=x+dx[i];
			if(!isRange(ny,nx)) continue;
			if(visited[ny][nx]) continue;
			if(board[ny][nx]!=board[y][x]) continue;
			visited[ny][nx]=1;
			q.push({ny,nx});
			tmp.push({ny,nx});
			++cnt;
		}
	}
	return cnt;
}
void solve(){
	while(1){
		pos=queue<pair<int,int>>();
		for(int i=0;i<n;++i){
			for(int j=0;j<10;++j){
				visited[i][j]=0;
			}
		}
		for(int i=0;i<n;++i){
			for(int j=0;j<10;++j){
				if(board[i][j]=='0') continue;
				if(visited[i][j]) continue;
				tmp=queue<pair<int,int>>();
				int cur_num=bfs(i,j);
				if(cur_num>=k){
					while(!tmp.empty()){
						pos.push(tmp.front());
						tmp.pop();
					}
				}
			}
		}
		if(pos.empty()){
			break;
		}
		int ps=pos.size();
		for(int i=0;i<ps;++i){
			board[pos.front().first][pos.front().second]='0';
			pos.pop();
		}
		// for(int i=0;i<n;++i){
		// 	for(int j=0;j<10;++j){
		// 		cout<<board[i][j];
		// 	}cout<<endl;
		// }
		// break;
		for(int i=0;i<10;++i){
			for(int j=n-2;j>=0;--j){
				// [j][i]
				if(board[j][i]=='0') continue;
				int cnt=0;
				for(int k=j+1;k<=n-1;++k){
					if(board[k][i]!='0'){
						break;
					}else{
						++cnt;
					}
				}
				if(cnt==0) continue;
				board[j+cnt][i]=board[j][i];
				board[j][i]='0';
			}
		}
		// for(int i=0;i<n;++i){
		// 	for(int j=0;j<10;++j){
		// 		cout<<board[i][j];
		// 	}cout<<endl;
		// }cout<<endl;
		// break;
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<10;++j){
			cout<<board[i][j];
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