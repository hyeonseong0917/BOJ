#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	int N=0;
	const int MAX=30+1;
	long long dp[MAX*2][MAX];
	while(1){
		cin>>N;
		if(N==0){
			break;
		}
		for(int i=0;i<MAX*2;++i){
			for(int j=0;j<MAX;++j){
				dp[i][j]=0;
			}
		}	
		dp[1][1]=1;
		for(int i=2;i<=60;++i){
			int k=min(i,N);
			
			for(int j=k;j>=1;--j){
				if(j*2<i){
					break;
				}
				dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
			}
		}
		// cout<<dp[4][2]<<endl;
		cout<<dp[N*2][N]<<"\n";
	}
	return 0;
}