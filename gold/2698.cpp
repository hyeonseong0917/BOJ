#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define ll long long

ll dp[100+1][100+1][2];

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		for(ll i=0;i<100+1;++i){
			for(ll j=0;j<100+1;++j){
				for(ll k=0;k<2;++k){
					dp[i][j][k]=0;
				}
			}
		}
		dp[1][0][0]=1;
		dp[1][1][0]=0;
		dp[1][1][1]=0;
		dp[1][0][1]=1;
		for(ll i=2;i<=100;++i){
			for(ll j=0;j<=i-1;++j){
				dp[i][j][0]=dp[i-1][j][0]+dp[i-1][j][1];
				dp[i][j][1]=dp[i-1][j][0];
				if(j>=1){
					dp[i][j][1]+=dp[i-1][j-1][1];
				}
			}
		}
		ll t;
		cin>>t;
		while(t--){
			ll n,k;
			cin>>n>>k;
			cout<<dp[n][k][0]+dp[n][k][1]<<"\n";
		}
	}
	return 0;
}