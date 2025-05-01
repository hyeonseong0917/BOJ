#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <cmath>
using namespace std;

#define ll long long
#define pb push_back

ll dp[5000+1][5000+1];
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=1;
	// cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
			for(ll j=0;j<=n;++j){
				dp[i][j]=-2023101800;
			}
		}
		// dp[x][y]: x인덱스까지 y개를 골랐을때의 최댓값
		// dp[x][y]=max(dp[x-1][y],dp[x-1][y-1]+v[x]-1);
		dp[0][0]=0;
		dp[0][1]=v[0];
		for(ll i=1;i<n;++i){
			dp[i][0]=0;
			for(ll j=1;j<=i+1;++j){
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]+v[i]-(j-1));
			}
		}
		ll ans=-2023101800;
		for(ll i=0;i<n;++i){
			ans=max(ans,dp[i][k]);
		}
		cout<<ans;
	}
} 