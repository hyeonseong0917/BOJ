#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX=1000+1;
int mod=1000000003;
int dp[MAX][MAX];
int vdp[MAX][MAX];
int sum=0;
int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int N,K;
	cin>>N>>K;
	for(int i=0;i<MAX;++i){
		for(int j=0;j<MAX;++j){
			dp[i][j]=0;
			vdp[i][j]=0;
		}
	}
	for(int i=0;i<N;++i){
		dp[i][1]=1;
		if(i>0){
			vdp[i][1]=1;
		}
	}
	for(int i=2;i<N-1;++i){
		for(int j=2;j<=K;++j){
			dp[i][j]=dp[i-1][j]%mod+dp[i-2][j-1]%mod;
			dp[i][j]%=mod;
		}
	}
	
	for(int i=3;i<N;++i){
		for(int j=2;j<=K;++j){
			vdp[i][j]=vdp[i-1][j]%mod+vdp[i-2][j-1]%mod;
			vdp[i][j]%=mod;
		}
	}
	for(int i=0;i<N-1;++i){
		sum+=dp[i][K]%mod;
		sum%=mod;
	}
	sum+=vdp[N-1][K];
	sum%=mod;
	cout<<sum;
	return 0;
}