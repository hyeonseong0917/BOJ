#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// cin>>o;
	while(1){
		ll n,m;
		cin>>n>>m;
		if(n==0 && m==0) break;
		vector<vector<ll>> board(n,vector<ll>(m,0));
		vector<vector<ll>> dp(n,vector<ll>(m,0));
		ll ans=0;
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				cin>>board[i][j];
				if(board[i][j]){
					dp[i][j]=1;
					ans=1;
				}
			}
		}
		
		for(ll i=1;i<n;++i){
			for(ll j=1;j<m;++j){
				if(!board[i][j]) continue;
				ll min_num=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
				dp[i][j]=min_num+1;
				ans=max(ans,dp[i][j]);
			}
		}
		cout<<ans<<"\n";
		
	}
	return 0;
}