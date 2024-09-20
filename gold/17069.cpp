#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define ll long long

ll dp[32+1][32+1][3+1];
ll dy[3]={1,1,0};
ll dx[3]={0,1,1};
ll board[32+1][32+1];
ll n;
bool isRange(ll y, ll x){
	return (y>=0 && x>=0 && y<n && x<n);
}
ll get_dp(ll y, ll x, ll d){
	if(!isRange(y,x)) return 0;
	if(board[y][x]==1) return dp[y][x][d]=0;
	if(d==1){
		ll fy=y;
		ll fx=x+1;

		ll sy=y+1;
		ll sx=x;
		if(board[fy][fx] || board[sy][sx]){
			return dp[y][x][d]=0;
		}
	}
	if(y==0 && x==1){
		if(d==0) return 0;
		return 1;
	} 
	if(dp[y][x][d]) return dp[y][x][d];
	if(d==0){
		return dp[y][x][d]=get_dp(y-dy[0],x-dx[0],0)+get_dp(y-dy[1],x-dy[1],1);
	}else if(d==1){
		return dp[y][x][d]=get_dp(y-dy[0],x-dx[0],0)+get_dp(y-dy[1],x-dy[1],1)+get_dp(y-dy[2],x-dx[2],2);
	}else{
		return dp[y][x][d]=get_dp(y-dy[2],x-dx[2],2)+get_dp(y-dy[1],x-dy[1],1);
	}
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
				cin>>board[i][j];
				for(ll k=0;k<4;++k){
					dp[i][j][k]=0;
				}
			}
		}
		ll sum=0;
		sum+=get_dp(n-1,n-1,1);
		cout<<sum;
	}
	return 0;
}