#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX=10000+1;
int dp[MAX];

int main() {
	int n=0;
	cin>>n;
	dp[1]=1;
	dp[2]=2;
	for(int i=3;i<=n;++i){
		dp[i]=(dp[i-1]+dp[i-2])%10007;
	}
	cout<<dp[n];
	return 0;
}