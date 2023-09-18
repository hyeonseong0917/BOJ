#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int MOD=1000000000;

int main() {
	// your code goes here
	int N=0;
	//dp[1][0]=0, dp[1][1]=1, dp[1][2]=1, dp[1][9]=1
	//dp[N][M]: 길이가 N이면서 M으로 끝나는 계단수의 개수
	//dp[N][M]=dp[N-1][M-1]+dp[N-1][M+1] M-1은 0보다 크거나 같아야 하고 M+1은 9보다 작거나 같아야 함
	cin>>N;
	long long dp[100+1][10+1];
	for(int i=0;i<101;++i){
		for(int j=0;j<11;++j){
			dp[i][j]=0;
		}
	}
	for(int i=1;i<10;++i){
		dp[1][i]=1;
	}

	for(int i=2;i<=N;++i){
		for(int j=0;j<=9;++j){
			if(j-1>=0){
				dp[i][j]+=dp[i-1][j-1];
			}
			if(j+1<=9){
				dp[i][j]+=dp[i-1][j+1];
			}
			dp[i][j]%=MOD;
		}
	}

	long long sum=0;
	for(int i=0;i<10;++i){
		sum+=dp[N][i]%MOD;
	}
	sum%=MOD;
	cout<<sum;
	return 0;
}