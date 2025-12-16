#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;

#define ll long long


int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		// 1328
		// n종류의 소가 있음
		// 1번종,2번종,3번종.. n번종까지 있음
		ll n;
		cin>>n;
		vector<ll> x(n,0), y(n,0);
		for(ll i=0;i<n;++i){
			cin>>x[i];
		}
		for(ll i=0;i<n;++i){
			cin>>y[i];
		}
		ll dp[n][n];
		for(ll i=0;i<n;++i){
			for(ll j=0;j<n;++j){
				dp[i][j]=0;
			}
		}
		for(ll i=0;i<n;++i){
			if((ll)abs(x[0]-y[i])<=4){
				dp[0][i]=1;
			}
			if((ll)abs(x[i]-y[0])<=4){
				dp[i][0]=1;
			}
		}
		for(ll i=1;i<n;++i){
			for(ll j=1;j<n;++j){
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				if((ll)abs(x[i]-y[j])<=4){
					dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
				}
			}
		}
		cout<<dp[n-1][n-1];
		// ll ans=0;
		// for(ll i=0;i<n;++i){
		// 	for(ll j=0;j<n;++j){
		// 		ans=max(ans,dp[i][j]);
		// 	}
		// }
		// cout<<ans;
	}
	return 0;
}