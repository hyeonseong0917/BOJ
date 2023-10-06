#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX=10000+5;

int dp[MAX][4]; 
// dp[x][n]: n으로 끝나는 경우의 수
// 중복을 피하기 위해 오름차순 정렬
// dp[1][1]=1, dp[2][1]=1, dp[2][2]=1, dp[3][1]=1, dp[3][2]=1, dp[3][3]=1
// dp[x][1]=dp[x-1][1], dp[x][2]=dp[x-2][1]+dp[x-2][2], dp[x][3]=dp[x-3][1]+dp[x-3][2]+dp[x-3][3]



int main() {
	// your code goes here
	for(int i=0;i<MAX;++i){
		for(int j=1;j<=3;++j){
			dp[i][j]=0;	
		}
	}
	dp[1][1]=1, dp[2][1]=1, dp[2][2]=1, dp[3][1]=1, dp[3][2]=1, dp[3][3]=1;
	int n=0;
	int t=0;
	cin>>t;
	for(int i=4;i<=10000;++i){
		dp[i][1]=dp[i-1][1];
		dp[i][2]=dp[i-2][1]+dp[i-2][2];
		dp[i][3]=dp[i-3][1]+dp[i-3][2]+dp[i-3][3];
	}
	while(t--){
		cin>>n;	
		
		int sum=0;
		for(int i=1;i<=3;++i){
			// cout<<i<<" "<<dp[n][i]<<endl;
			sum+=dp[n][i];
		}
		cout<<sum<<endl;
	}
	
	

	return 0;
}