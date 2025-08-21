#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

#define ll long long

ll n,m;
ll board[1000+1][1000+1];
ll dist[1000+1][1000+1];
ll check[1000+1][1000+1];
ll ly,lx,ry,rx,fy,fx;
ll dy[4]={-1,0,1,0};
ll dx[4]={0,1,0,-1};
ll h,w;
bool isRange(ll y, ll x){
	return (y>=0 && x>=0 && y<n && x<m);
}
void Input(){
	cin>>n>>m;
	for(ll i=0;i<n;++i){
		for(ll j=0;j<m;++j){
			cin>>board[i][j];
			dist[i][j]=2023101800;
			check[i][j]=0;
		}
	}
	
	cin>>h>>w>>ly>>lx>>fy>>fx;
	--ly;
	--lx;
	--fy;
	--fx;
	--h;
	--w;
	ry=ly+h-1;
	rx=lx+w-1;
}
void BFS(){
	dist[ly][lx]=0;
	queue<pair<ll,ll>> q;
	q.push({ly,lx});
	while(!q.empty()){
		ll y=q.front().first;
		ll x=q.front().second;
		q.pop();
		if(y==fy && x==fx){
			continue;
		}
		for(ll i=0;i<4;++i){
			ll ny=y+dy[i];
			ll nx=x+dx[i];
			ll nny=ny+h;
			ll nnx=nx+w;
			if(!isRange(ny,nx)) continue;
			if(board[ny][nx]) continue;
			if(check[ny][nx]) continue;
			if(!isRange(ny+h,nx+w)) continue;
			// [nny][x,x+w]에 1이 없는지?
			// [y,y+h][nnx]에 1이 없는지?
			bool flag=0;
			if(i==0){
				// 위로 올라감
				for(ll j=x;j<=x+w;++j){
					if(board[ny][j]){
						flag=1;
					}
				}
			}else if(i==1){
				// 오른쪽으로 감
				for(ll j=y;j<=y+h;++j){
					if(board[j][nnx]){
						flag=1;
					}
				}
			}else if(i==2){
				// 아래로 감
				for(ll j=x;j<=x+w;++j){
					if(board[nny][j]){
						flag=1;
					}
				}
			}else{
				// 왼쪽으로 감
				for(ll j=y;j<=y+h;++j){
					if(board[j][nx]){
						flag=1;
					}
				}
			}
			if(flag){
				check[ny][nx]=1;
				continue;
			}

			if(dist[ny][nx]>dist[y][x]+1){
				dist[ny][nx]=dist[y][x]+1;
				q.push({ny,nx});
			}
		}
	}
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		Input();
		BFS();
		if(dist[fy][fx]==2023101800){
			cout<<-1;
		}else{
			cout<<dist[fy][fx];
		}
	}
	return 0;
}