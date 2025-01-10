#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

#define ll long long

ll board[200+1][200+1];
ll dp[200+1][200+1];

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n,m;
		cin>>n>>m;
		for(ll i=0;i<=n;++i){
			for(ll j=0;j<=m;++j){
				dp[i][j]=0;
			}
		}
		for(ll i=1;i<=n;++i){
			for(ll j=1;j<=m;++j){
				cin>>board[i][j];
				dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+board[i][j];
			}
		}
		ll ans=-2023101800;
		for(ll i=1;i<=n;++i){
			for(ll j=1;j<=m;++j){
				for(ll k=0;k<i;++k){
					for(ll p=0;p<j;++p){
						ans=max(ans,dp[i][j]-dp[k][j]-dp[i][p]+dp[k][p]);
					}
				}
			}
		}
		
		cout<<ans;
	} 
	return 0;
}