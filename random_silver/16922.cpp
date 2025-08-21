#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

#define ll long long

ll v[4]={1,5,10,50};
ll n;
ll ans=0;

ll dp[1000+1][20+1];
int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		cin>>n;	
		for(ll i=0;i<=1000;++i){
			for(ll j=0;j<=20;++j){
				dp[i][j]=0;
			}
		}
		
		dp[1][1]=1;
		dp[5][1]=1;
		dp[10][1]=1;
		dp[50][1]=1;
		for(ll i=2;i<=1000;++i){
			for(ll j=2;j<=n;++j){
				// dp[i][j]: i만드는데 j개로 가능한지?
				for(ll k=0;k<4;++k){
					if(i>=v[k]){
						if(dp[i-v[k]][j-1]){
							++dp[i][j];
						}
					}
				}
			}
		}
		ll ans=0;
		for(ll i=1;i<=1000;++i){
			if(dp[i][n]){
				++ans;
			}
		}
		cout<<ans;
	}
	return 0;
}