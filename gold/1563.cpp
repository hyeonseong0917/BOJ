#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

#define ll long long


ll n;
ll dp[1000+1][2+1][3+1];

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		ll n;
		cin>>n;
		ll mod=1000000;
		for(ll i=0;i<1000+1;++i){
			for(ll j=0;j<2+1;++j){
				for(ll k=0;k<3+1;++k){
					dp[i][j][k]=0;
				}
			}
		}
		dp[0][0][0]=1;
		dp[0][0][1]=1;
		dp[0][1][0]=1;
		for(ll i=1;i<n;++i){
			dp[i][0][0]=(dp[i-1][0][0]+dp[i-1][0][1]+dp[i-1][0][2])%mod;
			dp[i][0][1]=dp[i-1][0][0]%mod;
			dp[i][0][2]=dp[i-1][0][1]%mod;

			dp[i][1][0]=(dp[i-1][1][0]+dp[i-1][0][0]+dp[i-1][0][1]+dp[i-1][0][2])%mod;
			dp[i][1][0]+=(dp[i-1][1][1]+dp[i-1][1][2])%mod;
			dp[i][1][1]=dp[i-1][1][0]%mod;
			dp[i][1][2]=dp[i-1][1][1]%mod;
		}
		ll ans=0;
		for(ll i=0;i<2;++i){
			for(ll j=0;j<3;++j){
				ans+=dp[n-1][i][j]%mod;
				ans%=mod;
			}
		}
		cout<<ans;
		
	}	
	return 0;
}