#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

#define ll long long


// 이웃한거 찾는건 ok인데 길이의 합을 어떻게 구할지?
// 
ll board[102][102];
ll is_out[102][102];
ll dy[2][6]={{-1,-1,0,1,1,0},{-1,-1,0,1,1,0}};
ll dx[2][6]={{-1,0,1,0,-1,-1},{0,1,1,1,0,-1}};
ll n,m;
bool isRange(ll y, ll x){
	return (y>=0 && x>=0 && y<=n+1 && x<=m+1);
}
void Input(){
	for(ll i=0;i<=101;++i){
		for(ll j=0;j<=101;++j){
			board[i][j]=0;
			is_out[i][j]=0;
		}
	}
	cin>>m>>n;
	for(ll i=1;i<=n;++i){
		for(ll j=1;j<=m;++j){
			cin>>board[i][j];
		}
	}
}
void BFS(){
	queue<pair<ll,ll>> q;
	is_out[0][0]=1;
	q.push({0,0});
	while(!q.empty()){
		ll y=q.front().first;
		ll x=q.front().second;
		// cout<<y<<" "<<x<<"\n";
		q.pop();
		for(ll i=0;i<6;++i){
			ll ny=y+dy[y%2][i];
			ll nx=x+dx[y%2][i];
			if(!isRange(ny,nx)) continue;
			if(is_out[ny][nx]) continue;
			if(board[ny][nx]==1) continue;
			is_out[ny][nx]=1;
			q.push({ny,nx});
		}
	}
	ll ans=0;
	for(ll i=1;i<=n;++i){
		for(ll j=1;j<=m;++j){
			for(ll k=0;k<6;++k){
				if(!board[i][j]) continue;
				ll ny=i+dy[i%2][k];
				ll nx=j+dx[i%2][k];
				if(is_out[ny][nx]) ++ans;
			}
		}
	}
	cout<<ans;
	// for(ll i=0;i<=n;++i){
	// 	for(ll j=0;j<=m;++j){
	// 		cout<<is_out[i][j];
	// 	}cout<<"\n";
	// }
}
void solve(){
	BFS();
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		Input();
		solve();
	}

	return 0;
}