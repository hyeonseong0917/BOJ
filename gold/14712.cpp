#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long

ll n,m;
ll board[25+1][25+1];
ll ans=0;
bool isRange(ll y, ll x){
	return (y>=0 && x>=0 && y<n && x<m);
}
void dfs(ll y, ll x){
	// cout<<y<<" "<<x<<" "<<cnt<<"\n";
	if(x==m){
		dfs(y+1,0);
		return;
	}
	if(y==n){
		++ans;
		return;
	}
	// 안넣고 다음칸
	dfs(y,x+1);
	// y,x에 넣기
	// y,x에 넣을 수 있는지?
	if(!isRange(y-1,x) || !isRange(y,x-1) || !isRange(y-1,x-1)){
		board[y][x]=1;
		dfs(y,x+1);
		board[y][x]=0;
	}else{
		if(board[y-1][x] && board[y][x-1] && board[y-1][x-1]){
			return;
		}else{
			board[y][x]=1;
			dfs(y,x+1);
			board[y][x]=0;
		}
	}
	
	
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		cin>>n>>m;
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				board[i][j]=0;
			}
		}
		// dfs(0,0,1);
		dfs(0,0);
		cout<<ans;
	}
	return 0;
}