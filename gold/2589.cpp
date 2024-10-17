#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define ll long long
const int MAX=50+1;
bool visited[MAX][MAX];
ll dy[4]={-1,0,1,0};
ll dx[4]={0,1,0,-1};
ll n,m;
bool isRange(ll y, ll x){
	return (y>=0 && x>=0 && y<n && x<m);
}
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		cin>>n>>m;
		string board[n];
		for(ll i=0;i<n;++i){
			cin>>board[i];
		}
		ll ans=-1;
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				if(board[i][j]=='W') continue;
				queue<pair<ll,pair<ll,ll>>> q;
				q.push({0,{i,j}});
				for(ll k=0;k<n;++k){
					for(ll p=0;p<m;++p){
						visited[k][p]=0;
					}
				}
				visited[i][j]=1;
				while(!q.empty()){
					ll cur_cnt=q.front().first;
					ll y=q.front().second.first;
					ll x=q.front().second.second;
					ans=max(ans,cur_cnt);
					q.pop();
					for(ll i=0;i<4;++i){
						ll ny=y+dy[i];
						ll nx=x+dx[i];
						if(!isRange(ny,nx)) continue;
						if(visited[ny][nx]) continue;
						if(board[ny][nx]=='W') continue;
						visited[ny][nx]=1;
						q.push({cur_cnt+1,{ny,nx}});
					}
				}
			}
		}
		cout<<ans;
	}
	return 0;
}