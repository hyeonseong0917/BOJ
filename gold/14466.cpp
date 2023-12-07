#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

int N,K,R;
const int MAX=100+1;
int g[MAX][MAX][MAX][MAX];
int can_go[MAX][MAX];
bool visited[MAX][MAX];
vector<pair<int,int>> cow;
int cow_num[MAX][MAX];
bool check[MAX];
void Input(){
	cin>>N>>K>>R;
	for(int i=0;i<R;++i){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		g[a][b][c][d]=1;
		g[c][d][a][b]=1;
	}
	for(int i=0;i<K;++i){
		for(int j=0;j<K;++j){
			can_go[i][j]=0;
			cow_num[i][j]=0;
		}
	}
	for(int i=0;i<K;++i){
		int y,x;
		cin>>y>>x;
		cow.push_back({y,x});
		cow_num[y][x]=i;
	}
	
}
bool flag=0;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
bool isRange(int y, int x){
	return(y>=1 && x>=1 && y<=N && x<=N);
}
int ans=0;
void bfs(int cur_cow){
	int cy=cow[cur_cow].first;
	int cx=cow[cur_cow].second;
	queue<pair<int,int>> q;
	q.push({cy,cx});
	visited[cy][cx]=1;

	while(!q.empty()){
		int y=q.front().first;
		int x=q.front().second;
		q.pop();
		for(int i=0;i<4;++i){
			int ny=y+dy[i];
			int nx=x+dx[i];
			if(!isRange(ny,nx)) continue;
			if(visited[ny][nx]) continue;
			if(g[y][x][ny][nx]) continue;
			if(cow_num[cy][cx]<cow_num[ny][nx]){
				++ans;
			}
			visited[ny][nx]=1;
			q.push({ny,nx});

		}
	}
}
void solve(){
	for(int i=0;i<K;++i){
		for(int j=1;j<=N;++j){
			for(int k=1;k<=N;++k){
				visited[j][k]=0;
			}
		}
		bfs(i);

	}
	
	cout<<K*(K-1)/2-ans;
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