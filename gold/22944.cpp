#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

#define ll long long


ll n,h,d;
char board[500][500];
ll dp[500][500];
ll INF=2023101800;
pair<ll,ll> S;
pair<ll,ll> F;
void Input(){
	cin>>n>>h>>d;
	for(ll i=0;i<n;++i){
		for(ll j=0;j<n;++j){
			cin>>board[i][j];
			dist[i][j]=INF;
			if(board[i][j]=='S'){
				S.first=i;
				S.second=j;
				dist[i][j]=0;
			}
			if(board[i][j]=='E'){
				F.first=i;
				F.second=j;
			}
			
		}
	}
}
ll dy[4]={-1,0,1,0};
ll dx[4]={0,1,0,-1};
bool isRange(ll y, ll x){
	return (y>=0 && x>=0 && y<n && x<n);
}
void solve(){
	queue<pair<pair<ll,ll>,pair<ll,ll>>> q;
	q.push({{h,0},{S.first,S.second}});
	// 최단거리로 기록되어 있을 수도 있는데, 해당 hp로는 도달 못하는 경우가 있을수도??
	while(!q.empty()){
		ll cur_hp=q.front().first.first;
		ll um_hp=q.front().first.second;
		ll y=q.front().second.first;
		ll x=q.front().second.second;
		q.pop();
		
	}

	if(dist[F.first][F.second]>=INF){
		cout<<-1;
	}else{
		cout<<dist[F.first][F.second];
	}
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