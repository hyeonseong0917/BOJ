#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

ll n,m;
char board[20+5][20+5];
vector<pair<ll,ll>> v;
ll ans=11;
// 4^10 2^20
// 2^10
ll dy[4]={-1,0,1,0};
ll dx[4]={0,1,0,-1};
ll dist[25][25][25][25];
bool isRange(ll y, ll x){
	return (y>=1 && x>=1 && y<=n && x<=m);
}
void BFS(pair<ll,ll> a, pair<ll,ll> b){
	queue<pair<pair<ll,ll>,pair<ll,ll>>> q;
	q.push({a,b});
	dist[a.first][a.second][b.first][b.second]=0;
	while(!q.empty()){
		pair<ll,ll> fst_pos=q.front().first;
		pair<ll,ll> sed_pos=q.front().second;
		ll fst_y=fst_pos.first;
		ll fst_x=fst_pos.second;
		ll sed_y=sed_pos.first;
		ll sed_x=sed_pos.second;
		q.pop();
		if(!isRange(fst_pos.first,fst_pos.second) || !isRange(sed_pos.first,sed_pos.second)){
			ans=min(ans,dist[fst_y][fst_x][sed_y][sed_x]);
			continue;
		}
		for(ll i=0;i<4;++i){
			ll fst_ny=fst_y+dy[i];
			ll fst_nx=fst_x+dx[i];
			ll sed_ny=sed_y+dy[i];
			ll sed_nx=sed_x+dx[i];
			if(!isRange(fst_ny,fst_nx) && !isRange(sed_ny,sed_nx)) continue;
			if(board[fst_ny][fst_nx]=='#'){
				fst_ny=fst_y;
				fst_nx=fst_x;
			}
			if(board[sed_ny][sed_nx]=='#'){
				sed_ny=sed_y;
				sed_nx=sed_x;
			}
			if(dist[fst_ny][fst_nx][sed_ny][sed_nx]>dist[fst_y][fst_x][sed_y][sed_x]+1){
				dist[fst_ny][fst_nx][sed_ny][sed_nx]=dist[fst_y][fst_x][sed_y][sed_x]+1;
				q.push({{fst_ny,fst_nx},{sed_ny,sed_nx}});
			}
		}
	}
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// cin>>o;
	while(o--){
		cin>>n>>m;
		for(ll i=1;i<=n;++i){
			for(ll j=1;j<=m;++j){
				cin>>board[i][j];
				if(board[i][j]=='o'){
					v.push_back({i,j});
					board[i][j]='.';
				}
			}
		}
		for(ll i=0;i<=21;++i){
			for(ll j=0;j<=21;++j){
				for(ll p=0;p<=21;++p){
					for(ll q=0;q<=21;++q){
						dist[i][j][p][q]=2023101800;		
					}
				}
			}
		}
		BFS(v[0],v[1]);
		if(ans==11){
			cout<<-1;
		}else{
			cout<<ans;
		}
	}	
	return 0;
}