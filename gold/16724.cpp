#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
using namespace std;

#define ll long long

ll n,m;
const int MAX=1000+1;
string board[MAX];
bool visited[MAX][MAX];
ll ans=0;
pair<ll,ll> parent[MAX][MAX];
pair<ll,ll> find(ll y, ll x){
	if(parent[y][x]==make_pair(y,x)){
		return {y,x};
	}
	return parent[y][x]=find(parent[y][x].first, parent[y][x].second);
}
void union_find(ll ny, ll nx, ll y, ll x){
	parent[ny][nx]=find(y,x);
}
ll dy[4]={-1,0,1,0};
ll dx[4]={0,1,0,-1};
void dfs(ll y, ll x){
	ll ny,nx;
	if(board[y][x]=='U'){
		ny=y+dy[0];
		nx=x+dx[0];
	}else if(board[y][x]=='R'){
		ny=y+dy[1];
		nx=x+dx[1];
	}else if(board[y][x]=='D'){
		ny=y+dy[2];
		nx=x+dx[2];
	}else{
		ny=y+dy[3];
		nx=x+dx[3];
	}
	if(!visited[ny][nx]){
		visited[ny][nx]=1;
		union_find(ny,nx,y,x);
		dfs(ny,nx);
	}else{
		if(parent[y][x]==parent[ny][nx]){
			++ans;
		}
		return;
	}
}
int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		cin>>n>>m;
		for(ll i=0;i<n;++i){
			cin>>board[i];
		}
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				parent[i][j]={i,j};
			}
		}
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				if(!visited[i][j]){
					visited[i][j]=1;
					dfs(i,j);
				}
			}
		}
		cout<<ans;

	}
	return 0;
}