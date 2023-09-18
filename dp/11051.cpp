#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int MOD=10007;
const int MAX=1000+1;
int main() {
	// your code goes here
	int N=0,K=0;
	cin>>N>>K;
	long long dp[1001][1001]; //dp[N][K]=nCk
	for(int i=0;i<MAX;++i){
		for(int j=0;j<MAX;++j){
			dp[i][j]=0;
		}
	}
	for(long long i=1;i<=N;++i){
		dp[i][1]=i;
		dp[i][0]=1;
	}
	for(int i=2;i<=N;++i){
		for(int j=2;j<=K;++j){
			dp[i][j]=(dp[i-1][j-1]%MOD+dp[i-1][j]%MOD)%MOD;
		}
	}
	cout<<dp[N][K];

	
	return 0;
}