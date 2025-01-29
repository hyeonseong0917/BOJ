#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

#define ll long long

ll r,c;
ll dy[8]={-1,-1,-1,0,0,1,1,1};
ll dx[8]={-1,0,1,-1,1,-1,0,1};
bool isRange(ll y, ll x){
	return (y>=0 && x>=0 && y<r && x<c);
}
pair<ll,ll> cache[500+1][500+1];
ll board[500+1][500+1];
ll ans[500+1][500+1];

pair<ll,ll> dp(ll y, ll x){
	// cout<<y<<" "<<x<<endl;
	// y,x가제일 작은 수인지??
	ll cur_num=board[y][x];
	bool is_small=1;
	ll small_num=2023101800;
	ll small_y=-1;
	ll small_x=-1;
	for(ll i=0;i<8;++i){
		ll ny=y+dy[i];
		ll nx=x+dx[i];
		if(!isRange(ny,nx)) continue;
		if(cur_num>board[ny][nx]){
			is_small=0;
		}
		if(small_num>board[ny][nx]){
			small_num=board[ny][nx];
			small_y=ny;
			small_x=nx;
		}
	}
	if(is_small){
		++ans[y][x];
		return {y,x};
	}
	if(cache[y][x].first!=-1 && cache[y][x].second!=-1){
		++ans[cache[y][x].first][cache[y][x].second];
		return {cache[y][x].first,cache[y][x].second};
	}
	return cache[y][x]=dp(small_y,small_x);

}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		cin>>r>>c;
		for(ll i=0;i<r;++i){
			for(ll j=0;j<c;++j){
				cin>>board[i][j];
				cache[i][j].first=-1;
				cache[i][j].second=-1;
				ans[i][j]=0;
			}
		}
		for(ll i=0;i<r;++i){
			for(ll j=0;j<c;++j){
				dp(i,j);
			}
		}
		for(ll i=0;i<r;++i){
			for(ll j=0;j<c;++j){
				cout<<ans[i][j]<<" ";
			}cout<<"\n";
		}
	} 
	return 0;
}