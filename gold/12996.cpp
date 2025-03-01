#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

ll dp[50+1][50+1][50+1][50+1];

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		// s개의 곡을 녹음해야함
		// 1325
		ll s,a,b,c;
		cin>>s>>a>>b>>c;
		ll mod=1000000007;
		// 3 3 1 1
		if(s>a+b+c){
			cout<<0;
			continue;
		}
		ll ans=0;
		
		dp[0][0][0][0]=0;
		for(ll i=0;i<=1;++i){
			for(ll j=0;j<=1;++j){
				for(ll k=0;k<=1;++k){
					if(i==0 && j==0 && k==0) continue;
					dp[1][i][j][k]=1;
				}
			}
		}
		for(ll i=2;i<=s;++i){
			for(ll j=0;j<=i;++j){
				for(ll k=0;k<=i;++k){
					for(ll p=0;p<=i;++p){
						dp[i][j][k][p]=0;
						ll c=0;
						if(j>0){
							c+=dp[i-1][j-1][k][p]%mod;
						}
						if(k>0){
							c+=dp[i-1][j][k-1][p]%mod;
						}
						if(p>0){
							c+=dp[i-1][j][k][p-1]%mod;
						}
						if(j>0 && k>0){
							c+=dp[i-1][j-1][k-1][p]%mod;
						}
						if(j>0 && p>0){
							c+=dp[i-1][j-1][k][p-1]%mod;
						}
						if(k>0 && p>0){
							c+=dp[i-1][j][k-1][p-1]%mod;
						}
						if(j>0 && k>0 && p>0){
							c+=dp[i-1][j-1][k-1][p-1]%mod;
						}
						c%=mod;
						dp[i][j][k][p]=c;
					}
				}
			}
		}
		cout<<dp[s][a][b][c];

	}
	return 0;
}