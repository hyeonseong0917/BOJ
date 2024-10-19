#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define ll long long

const int MAX=300000+1;
ll dp[MAX],d[MAX],DP[MAX],psum[MAX];
ll INF=2023101800;

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n;
		cin>>n;
		for(ll i=0;i<MAX;++i){
			dp[i]=0;
			d[i]=0;
			DP[i]=INF;
			psum[i]=0;
		}
		d[1]=1;
		for(ll i=2;i<=n;++i){
			d[i]=d[i-1]+i;
			if(d[i]>=300000) break;
		}
		dp[1]=1;
		for(ll i=2;i<=n;++i){
			for(ll j=1;j<=i;++j){
				dp[i]+=d[j];
			}
			if(dp[i]>=300000) break;
			// cout<<i<<" "<<dp[i]<<endl;
		}
		
		DP[0]=0;
		DP[1]=1;
		for(ll i=2;i<=n;++i){
			for(ll j=1;j<=n;++j){
				if(i<dp[j]) break;
				DP[i]=min(DP[i],DP[i-dp[j]]+1);
			}
		}
		
		// cout<<DP[4]<<endl;
		cout<<DP[n];
		
	}
	return 0;
}