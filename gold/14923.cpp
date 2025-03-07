#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

ll n,m,hx,hy,ex,ey;
const int MAX=1000+1;
ll board[MAX][MAX];
ll dy[4]={-1,0,1,0};
ll dx[4]={0,1,0,-1};
ll dist[MAX][MAX][2];
bool isRange(ll y, ll x){
	return (y>=0 && x>=0 && y<n && x<m);
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// cin>>o;
	while(o--){
		cin>>n>>m;
		cin>>hx>>hy;
		cin>>ex>>ey;
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				cin>>board[i][j];
				dist[i][j][0]=2023101800;
				dist[i][j][1]=2023101800;
			}
		}
		--hx;
		--hy;
		--ex;
		--ey;
		queue<pair<ll,pair<ll,ll>>> q;
		q.push({1,{hx,hy}});
		dist[hx][hy][1]=0;
		ll ans=2023101800;
		while(!q.empty()){
			ll flag=q.front().first;
			ll y=q.front().second.first;
			ll x=q.front().second.second;
			// cout<<y<<" "<<x<<" "<<flag<<" "<<dist[y][x][flag]<<endl;
			if(y==ex && x==ey){
				ans=min(ans,dist[y][x][flag]);
			}
			q.pop();
			for(ll i=0;i<4;++i){
				ll ny=y+dy[i];
				ll nx=x+dx[i];
				if(!isRange(ny,nx)) continue;
				if(!flag){
					if(board[ny][nx]==1) continue;
					if(dist[ny][nx][0]>dist[y][x][0]+1){
						dist[ny][nx][0]=dist[y][x][0]+1;
						q.push({0,{ny,nx}});
					}
				}else{
					if(board[ny][nx]==1){
						if(dist[ny][nx][0]>dist[y][x][1]+1){
							dist[ny][nx][0]=dist[y][x][1]+1;
							q.push({0,{ny,nx}});
						}
					}else{
						if(dist[ny][nx][1]>dist[y][x][1]+1){
							dist[ny][nx][1]=dist[y][x][1]+1;
							q.push({1,{ny,nx}});
						}
					}

				}
				
				
			}
		}
		if(ans==2023101800){
			cout<<-1;
		}else{
			cout<<ans;
		}
	}
	return 0;
}