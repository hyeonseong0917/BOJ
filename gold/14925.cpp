#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

#define ll long long

ll board[1000+1][1000+1];
ll dp[1000+1][1000+1];

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll m,n;
		cin>>m>>n;
		ll ans=0;
		for(ll i=0;i<m;++i){
			for(ll j=0;j<n;++j){
				cin>>board[i][j];
				dp[i][j]=0;
				if(board[i][j]==0){
					dp[i][j]=1;
				}
				ans=max(ans,dp[i][j]);
			}
		}
		
		for(ll i=1;i<m;++i){
			for(ll j=1;j<n;++j){
				if(board[i][j]!=0) continue;
				dp[i][j]=min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]))+1;
				ans=max(ans,dp[i][j]);
			}
		}
		cout<<ans;
	} 
	return 0;
}