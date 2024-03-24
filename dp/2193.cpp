#include <iostream>
using namespace std;
#define ll long long
int main() {
	// your code goes here
	int N;
	cin>>N;
	ll dp[90+1][2+1];
	for(ll i=0;i<=90;++i){
		for(ll j=0;j<2;++j){
			dp[i][j]=0;
		}
	}
	if(N==1 || N==2){
		cout<<1;
	}else{
		dp[0][1]=1;
		dp[1][0]=1;
		for(ll i=2;i<N;++i){
			dp[i][0]=dp[i-1][0]+dp[i-1][1];
			dp[i][1]=dp[i-1][0];
			// cout<<i<<" "<<dp[i][0]<<" "<<dp[i][1]<<endl;
		}
		cout<<dp[N-1][0]+dp[N-1][1];
	}
	return 0;
}