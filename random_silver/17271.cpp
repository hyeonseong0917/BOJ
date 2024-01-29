#include <iostream>
using namespace std;

#define ll long long
ll dp[10000+1];
ll N,M;
ll MOD=1000000007;
int main() {
	// your code goes here
	cin>>N>>M;
	dp[1]=1;
	for(ll i=2;i<M;++i){
		dp[i]=1;
	}
	dp[M]=2;
	for(ll i=M+1;i<=N;++i){
		dp[i]=(dp[i-1]%MOD+dp[i-M]%MOD)%MOD;
	}
	cout<<dp[N];
	return 0;
}