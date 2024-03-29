#include <iostream>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ll N;
	ll mod=1000000000;
	cin>>N;
	ll dp[1000000+1];
	for(ll i=0;i<=N;++i){
		dp[i]=0;
	}
	dp[1]=0;
	dp[2]=1;
	dp[3]=2;
	for(ll i=4;i<=N;++i){
		dp[i]=(i-1)*(((dp[i-2]%mod) + (dp[i-1]%mod))%mod);
		dp[i]%=mod;
	}
	cout<<dp[N];
	return 0;
}	