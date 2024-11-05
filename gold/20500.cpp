#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define ll long long

ll dp[1515+1][5+1][2+1];
ll mod=1000000007;
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n;
		cin>>n;
		for(ll i=0;i<1515+1;++i){
			for(ll j=0;j<5+1;++j){
				for(ll k=0;k<2+1;++k){
					dp[i][j][k]=0;
				}
			}
		}
		dp[0][1][1]=1;
		dp[0][5][2]=1;
		for(ll i=1;i<n;++i){
			dp[i][1][0]=(dp[i-1][1][2]+dp[i-1][5][2])%mod;
			dp[i][1][1]=(dp[i-1][1][0]+dp[i-1][5][0])%mod;
			dp[i][1][2]=(dp[i-1][1][1]+dp[i-1][5][1])%mod;
			dp[i][5][0]=(dp[i-1][1][1]+dp[i-1][5][1])%mod;
			dp[i][5][1]=(dp[i-1][1][2]+dp[i-1][5][2])%mod;
			dp[i][5][2]=(dp[i-1][1][0]+dp[i-1][5][0])%mod;
		}
		cout<<dp[n-1][5][0];
	}
	return 0;
}