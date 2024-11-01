#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define ll long long

ll n,m,k;
bool isRange(ll y, ll x){
	return (y>=0 && x>=0 && y<n && x<m);
}
ll dy[4]={-1,0,1,0};
ll dx[4]={0,1,0,-1};
const int MAX=100+1;
string s;
string board[MAX];
ll dp[MAX][MAX][80+1]; //[y][x][idx]: [y][x]에 s의 idx를 가져갔을 때
ll ss;
ll dfs(ll y, ll x, ll idx){
	if(dp[y][x][idx]!=-1) return dp[y][x][idx];
	if(idx==ss-1) return 1;
	dp[y][x][idx]=0;
	for(ll i=1;i<=k;++i){
		for(ll j=0;j<4;++j){
			ll ny=y+dy[j]*i;
			ll nx=x+dx[j]*i;
			if(!isRange(ny,nx)) continue;
			if(board[ny][nx]!=s[idx+1]) continue;
			dp[y][x][idx]+=dfs(ny,nx,idx+1);
		}
	}
	return dp[y][x][idx];
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		cin>>n>>m>>k;
		for(ll i=0;i<n;++i){
			cin>>board[i];
		}
		cin>>s;
		ss=s.size();
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				for(ll x=0;x<ss;++x){
					dp[i][j][x]=-1;
				}
			}
		}
		ll ans=0;
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				if(board[i][j]==s[0]){
					ans+=dfs(i,j,0);
				}
			}
		}
		
		cout<<ans;
	}
	return 0;
}