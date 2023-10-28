#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long

ll dp[11][2000+1];

int main() {
	// your code goes here
	ll t;
	cin>>t;
	for(ll i=0;i<11;++i){
		for(ll j=0;j<2001;++j){
			dp[i][j]=0;
		}
	}
	for(ll i=1;i<=2000;++i){
		dp[1][i]=1;
	}
	for(ll i=2;i<=10;++i){
		ll min_len=pow(2,i-1);
		for(ll j=min_len;j<=2000;++j){
			ll cur_num=0;
			ll second_min_len=pow(2,i-2);
			for(ll k=min(j/2,(ll)pow(2,i-2));k<=max(j/2,(ll)pow(2,i-2));++k){
				dp[i][j]+=dp[i-1][k];
			}
		}
	}
	while(t--){
		ll n,m;
		cin>>n>>m;
		ll min_m=pow(2,n-1);
		ll sum=0;
		for(ll i=min_m;i<=m;++i){
			// cout<<i<<" "<<dp[n][i]<<"\n";
			sum+=dp[n][i];
		}
		cout<<sum<<"\n";
	}

	return 0;
}