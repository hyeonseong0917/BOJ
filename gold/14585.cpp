#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long

ll board[300+1][300+1];
ll dp[300+1][300+1];
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n,m;
		cin>>n>>m;
		for(ll i=0;i<=300;++i){
			for(ll j=0;j<=300;++j){
				board[i][j]=0;
				dp[i][j]=0;
			}
		}
		// 사탕바구니 n개, 사탕은 m개씩 있음
		// n<=300, m<=10^6, x,y<=300
		for(ll i=0;i<n;++i){
			ll x,y;
			cin>>x>>y;
			board[y][x]=m;
		}
		ll ans=0;
		for(ll i=0;i<=300;++i){
			for(ll j=0;j<=300;++j){
				if(i==0 && j==0) continue;
				ll cur_time=i+j;
				if(i){
					dp[i][j]=max(dp[i-1][j],dp[i][j]);
				}
				if(j){
					dp[i][j]=max(dp[i][j],dp[i][j-1]);
				}
				if(board[i][j]){	
					dp[i][j]+=max(0ll,m-cur_time);
				}
				ans=max(ans,dp[i][j]);
			}
		}
		cout<<ans;
	}
	return 0;
}