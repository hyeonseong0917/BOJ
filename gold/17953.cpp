#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		// 디저트는 하루에 한 가지만
		ll n,m;
		cin>>n>>m;
		vector<vector<ll>> v;
		vector<vector<ll>> dp;
		for(ll i=0;i<m;++i){
			vector<ll> tmp(n,0);
			for(ll j=0;j<n;++j){
				cin>>tmp[j];
			}
			v.push_back(tmp);
		}
		for(ll i=0;i<n;++i){
			vector<ll> tmp(m,0);
			dp.push_back(tmp);
		}
		// dp[x][y]=x번째날에 y번째 디저트를 먹었을 때 최대값
		// dp[x][y]=max(dp[x-1][y]+v[x][y]/2,dp[x-1][y']+v[x][y])
		ll ans=0;
		for(ll i=0;i<m;++i){
			dp[0][i]=v[i][0];
			ans=max(ans,dp[0][i]);
		}
		
		for(ll i=1;i<n;++i){
			for(ll j=0;j<m;++j){
				for(ll k=0;k<m;++k){
					if(j==k){
						dp[i][j]=max(dp[i][j],dp[i-1][j]+v[j][i]/2);
					}else{
						dp[i][j]=max(dp[i][j],dp[i-1][k]+v[j][i]);
					}
					
				}
				if(i==n-1){
					// cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
					ans=max(ans,dp[i][j]);
				}
			}
		}
		cout<<ans;
	}	
	return 0;
}