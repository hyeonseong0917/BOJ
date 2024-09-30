#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;

#define ll long long

ll n,m;
const int MAX=1000+1;
ll board[MAX][MAX];
ll dp[MAX][MAX][4+1];
ll dy[4]={-1,0,1,0};
ll dx[4]={0,1,0,-1};
bool isRange(ll y, ll x){
	return (y>=0 && x>=0 && y<n && x<m);
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		cin>>n>>m;
		ll INF=-2023101800;
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				cin>>board[i][j];
				for(ll k=0;k<4;++k){
					dp[i][j][k]=INF;
				}
			}
		}
		dp[0][0][1]=board[0][0];
		dp[0][0][2]=board[0][0];
		dp[0][1][1]=board[0][0]+board[0][1];
		dp[1][0][2]=board[0][0]+board[1][0];

		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				if(i==0 && j==0) continue;
				for(ll k=1;k<4;++k){
					// dp[i][j][k]
					if(k==1){
						ll ny=i-dy[k];
						ll nx=j-dx[k];
						if(isRange(ny,nx)){
							dp[i][j][k]=max(dp[i][j][k],max(dp[ny][nx][1],dp[ny][nx][2])+board[i][j]);
						}
					}else if(k==2){
						ll ny=i-dy[k];
						ll nx=j-dx[k];
						if(isRange(ny,nx)){
							dp[i][j][k]=max(dp[i][j][k],max(dp[ny][nx][1],max(dp[ny][nx][2],dp[ny][nx][3]))+board[i][j]);
						}
					}else{
						ll ny=i-dy[k];
						ll nx=j-dx[k];
						if(isRange(ny,nx)){
							dp[i][j][k]=max(dp[i][j][k],max(dp[ny][nx][3],dp[ny][nx][2])+board[i][j]);
						}
					}
				}
			}
			for(ll j=m-1;j>=0;--j){
				if(i==0 && j==0) continue;
				for(ll k=1;k<4;++k){
					// dp[i][j][k]
					if(k==1){
						ll ny=i-dy[k];
						ll nx=j-dx[k];
						if(isRange(ny,nx)){
							dp[i][j][k]=max(dp[i][j][k],max(dp[ny][nx][1],dp[ny][nx][2])+board[i][j]);
						}
					}else if(k==2){
						ll ny=i-dy[k];
						ll nx=j-dx[k];
						if(isRange(ny,nx)){
							dp[i][j][k]=max(dp[i][j][k],max(dp[ny][nx][1],max(dp[ny][nx][2],dp[ny][nx][3]))+board[i][j]);
						}
					}else{
						ll ny=i-dy[k];
						ll nx=j-dx[k];
						if(isRange(ny,nx)){
							dp[i][j][k]=max(dp[i][j][k],max(dp[ny][nx][3],dp[ny][nx][2])+board[i][j]);
						}
					}
				}
			}
		}
		
		ll ans=max(dp[n-1][m-1][1],dp[n-1][m-1][2]);
		cout<<ans<<"\n";
		
	}
	return 0;
}
