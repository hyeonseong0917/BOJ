#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;

#define ll long long

ll dp[100+1][10][3][2];
int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		// 연속해서 1개 증가
		// 연속해서 2개 증가
		// 연속해서 1개 감소
		// 연속해서 2개 감소
		// 길이, 마지막 수, 연속 몇 개인지, 방향
		// dp[100][10][3][2]
		// 방향 0: 증가
		// 방향 1: 감소
		// dp[y][x][1][0]=dp[y-1][x-1][2][1]+dp[y-1][x-1][1][1]+dp[y-1][x-1][0][0]
		ll mod=1000000007;
		ll n;
		cin>>n;
		if(n==1){
			cout<<10;
			break;
		}
		for(ll i=0;i<=100;++i){
			for(ll j=0;j<10;++j){
				for(ll k=0;k<3;++k){
					for(ll p=0;p<2;++p){
						dp[i][j][k][p]=0;
					}
				}
			}
		}
		for(ll i=0;i<10;++i){
			if(i){
				dp[2][i][1][0]=1;
			}
			if(i!=9){
				dp[2][i][1][1]=1;
			}
		}
		
		for(ll i=3;i<=n;++i){
			for(ll j=0;j<10;++j){
				// 길이 i, 마지막 수 j, 연속 1개, 방향은 증가하는
				if(j){
					dp[i][j][1][0]=dp[i-1][j-1][1][1]%mod+dp[i-1][j-1][2][1]%mod;
					dp[i][j][1][0]%=mod;

					dp[i][j][2][0]=dp[i-1][j-1][1][0]%mod;
				}
				if(j!=9){
					dp[i][j][1][1]=dp[i-1][j+1][1][0]%mod+dp[i-1][j+1][2][0]%mod;
					dp[i][j][1][1]%=mod;
					dp[i][j][2][1]=dp[i-1][j+1][1][1]%mod;
				}
			}
		}
		ll ans=0;
		for(ll i=0;i<=9;++i){
			ans+=dp[n][i][1][0]%mod+dp[n][i][2][0]%mod+dp[n][i][1][1]%mod+dp[n][i][2][1]%mod;
			ans%=mod;
		}
		cout<<ans;
		
	}
	return 0;
}
