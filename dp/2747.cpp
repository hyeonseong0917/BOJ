#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n=0;
	cin>>n;
	int dp[45+1]={0,};
	dp[0]=0;
	dp[1]=1;
	dp[2]=1;
	for(int i=3;i<=45;++i){
		dp[i]=dp[i-1]+dp[i-2];
	}
	cout<<dp[n];
	return 0;
}