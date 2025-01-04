#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

#define ll long long

ll dp[100+1][100+1][2][2];
ll dy[2]={1,0};
ll dx[2]={0,1};
ll w,h;
ll mod=100000;
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		cin>>w>>h;
		for(ll i=0;i<=100;++i){
			for(ll j=0;j<=100;++j){
				for(ll k=0;k<2;++k){
					for(ll p=0;p<2;++p){
						dp[i][j][k][p]=0;
					}
				}
			}
		}
		for(ll i=2;i<=h;++i){
			dp[i][1][0][0]=1;
		}
		for(ll i=2;i<=w;++i){
			dp[1][i][0][1]=1;
		}
		for(ll i=2;i<=h;++i){
			for(ll j=2;j<=w;++j){
				// 1. dp[i][j][0][0]
				// 2. dp[i][j][0][1]
				// 3. dp[i][j][1][0]
				// 4. dp[i][j][1][1]
				dp[i][j][0][0]=(dp[i-1][j][0][0]+dp[i-1][j][1][0])%mod;
				dp[i][j][0][1]=(dp[i][j-1][0][1]+dp[i][j-1][1][1])%mod;
				dp[i][j][1][0]=(dp[i-1][j][0][1])%mod;
				dp[i][j][1][1]=(dp[i][j-1][0][0])%mod;
			}
		}
		cout<<(dp[h][w][0][0]+dp[h][w][0][1]+dp[h][w][1][0]+dp[h][w][1][1])%mod;
	}
	return 0;
}