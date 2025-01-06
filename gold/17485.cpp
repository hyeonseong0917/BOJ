#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

#define ll long long

ll dp[1000+1][1000+1][3]; // i는 전에 움직인 방향
ll dy[3]={1,1,1};
ll dx[3]={-1,0,1};
// 0은 왼쪽 대각선 아래, 1은 바로 아래, 2는 오른쪽 대각선 아래
ll board[1000+1][1000+1];
ll n,m;
ll INF=2023101800;
bool isRange(ll y, ll x){
	return (y>=0 && x>=0 && y<n && x<m);
}
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		
		cin>>n>>m;
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				cin>>board[i][j];
				dp[i][j][0]=INF;
				dp[i][j][1]=INF;
				dp[i][j][2]=INF;
			}
		}
		for(ll i=1;i<m-1;++i){
			for(ll j=0;j<3;++j){
				dp[0][i][j]=board[0][i];
			}
		}
		dp[0][0][1]=board[0][0];
		dp[0][0][0]=board[0][0];
		dp[0][m-1][0]=board[0][m-1];
		dp[0][m-1][2]=board[0][m-1];

		for(ll i=1;i<n;++i){
			for(ll j=0;j<m;++j){
				for(ll k=0;k<3;++k){
					// dp[i][j][k]: i,j에 k방향으로 진입
					if(j==0 && k==2) continue;
					if(j==m-1 && k==0) continue;
					ll ny=i-dy[k];
					ll nx=j-dx[k];
					if(!isRange(ny,nx)) continue;
					for(ll p=0;p<3;++p){
						if(k==p) continue;
						dp[i][j][k]=min(dp[i][j][k],dp[ny][nx][p]+board[i][j]);
					}
				}
			}
		}
		// cout<<dp[1][1][2]<<endl;
		// cout<<dp[2][0][0]<<endl;
		ll ans=INF;
		for(ll i=0;i<m;++i){
			for(ll j=0;j<3;++j){
				ans=min(ans,dp[n-1][i][j]);
			}
		}
		cout<<ans;	
	}
	return 0;
}