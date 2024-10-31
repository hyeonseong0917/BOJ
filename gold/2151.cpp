#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define ll long long

const int MAX=50+1;
string board[MAX];
ll dist[MAX][MAX][4+1];
ll INF=2023101800;
ll dy[4]={-1,0,1,0};
ll dx[4]={0,1,0,-1};
ll n;

bool isRange(ll y, ll x){
	return (y>=0 && x>=0 && y<n && x<n);
}

// /
ll fst_turn(ll d){
	if(d==0){
		return 1;
	}else if(d==1){
		return 0;
	}else if(d==2){
		return 3;
	}else{
		return 2;
	}
	return 0;
}

// 
ll sed_turn(ll d){
	if(d==0){
		return 3;
	}else if(d==1){
		return 2;
	}else if(d==2){
		return 1;
	}else{
		return 0;
	}
	return 0;
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		
		cin>>n;
		for(ll i=0;i<n;++i){
			for(ll j=0;j<n;++j){
				for(ll k=0;k<4;++k){
					dist[i][j][k]=INF;
				}
			}
		}
		vector<pair<ll,ll>> p;
		for(ll i=0;i<n;++i){
			cin>>board[i];
			for(ll j=0;j<n;++j){
				if(board[i][j]=='#'){
					p.push_back({i,j});
				}
			}
		}
		ll cy=p[0].first;
		ll cx=p[0].second;
		ll fy=p[1].first;
		ll fx=p[1].second;
		dist[cy][cx][0]=0;
		dist[cy][cx][1]=0;
		dist[cy][cx][2]=0;
		dist[cy][cx][3]=0;
		queue<pair<pair<ll,ll>,ll>> q;
		q.push({{cy,cx},0});
		q.push({{cy,cx},1});
		q.push({{cy,cx},2});
		q.push({{cy,cx},3});
		// dist[y][x]: y,x도달하기까지 필요한 거울의 최소 개수
		ll ans=INF;
		while(!q.empty()){
			ll y=q.front().first.first;
			ll x=q.front().first.second;
			ll d=q.front().second;
			q.pop();
			if(y==fy && x==fx){
				ans=min(ans,dist[y][x][d]);
				continue;
			}
			ll ny=y+dy[d];
			ll nx=x+dx[d];
			if(!isRange(ny,nx)) continue;
			if(board[ny][nx]=='*') continue;
			if(board[ny][nx]=='.' || board[ny][nx]=='#'){
				if(dist[ny][nx][d]>dist[y][x][d]){
					q.push({{ny,nx},d});
					dist[ny][nx][d]=dist[y][x][d];
				}
			}else if(board[ny][nx]=='!'){
				// 방향 바꾸기
				ll fd=fst_turn(d);
				if(dist[ny][nx][fd]>dist[y][x][d]+1){
					dist[ny][nx][fd]=dist[y][x][d]+1;
					q.push({{ny,nx},fd});
				}

				ll sd=sed_turn(d);
				if(dist[ny][nx][sd]>dist[y][x][d]+1){
					dist[ny][nx][sd]=dist[y][x][d]+1;
					q.push({{ny,nx},sd});
				}
				if(dist[ny][nx][d]>dist[y][x][d]){
					dist[ny][nx][d]=dist[y][x][d];
					q.push({{ny,nx},d});
				}
			}
		}
		// cout<<dist[3][1][2]<<"\n";
		cout<<ans;
	}

	return 0;
}