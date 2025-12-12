#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

// N: (i-1,j)
// S: (i+1,j)
// W: (i,j-1)
// E: (i,j+1)
ll check[1000+1][1000+1];
string board[1000+1];
ll n,m;
ll cnt=0;
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<n && x<m);
}
// NESW
ll dy[4]={-1,0,1,0};
ll dx[4]={0,1,0,-1};
map<char,ll> dir;
bool flag=0;
ll ans=0;
void BFS(ll cy, ll cx, ll cur_cnt){
	queue<pair<ll,ll>> q;
	q.push({cy,cx});
	check[cy][cx]=cur_cnt;
	ll fy=cy;
	ll fx=cx;
	while(!q.empty()){
		ll y=q.front().first;
		ll x=q.front().second;
		fy=y;
		fx=x;
		q.pop();
		char c=board[y][x];
		ll ny=y+dy[dir[c]];
		ll nx=x+dx[dir[c]];
		if(!isRange(ny,nx)) continue;
		if(check[ny][nx]==cur_cnt){
			break;
		}
		if(check[ny][nx] && check[ny][nx]!=cur_cnt){
			flag=1;
			break;
		}
		check[ny][nx]=cur_cnt;
		q.push({ny,nx});
	}
	if(flag){
		--ans;
	}

}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		dir['N']=0;
		dir['E']=1;
		dir['S']=2;
		dir['W']=3;
		cin>>n>>m;
		for(ll i=0;i<n;++i){
			cin>>board[i];
		}
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				check[i][j]=0;
			}
		}
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				if(!check[i][j]){
					flag=0;
					++cnt;
					++ans;
					// cout<<i<<" "<<j<<" "<<cnt<<"\n";
					BFS(i,j,cnt);
					// cout<<i<<" "<<j<<" "<<cnt<<"\n";
				}
			}
		}
		cout<<ans;
	}
	return 0;
}