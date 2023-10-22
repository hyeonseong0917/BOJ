#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

#define ll long long

ll dp[1000000+1];
ll MOD=1000000000;
int main() {
	// your code goes here
	int N;
	cin>>N;
	for(int i=0;i<1000000+1;++i){
		dp[i]=0;
	}
	dp[0]=1;
	dp[1]=1;
	dp[2]=2;
	dp[3]=2;
	for(ll i=4;i<=N;++i){
		if(i%2==1){
			dp[i]=(dp[i-1])%MOD;
		}else{
			dp[i]=(dp[i-1]+dp[i/2])%MOD;
		}
		
	}
	cout<<dp[N]%MOD;
	return 0;
}