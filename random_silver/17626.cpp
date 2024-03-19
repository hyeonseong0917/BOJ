#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

#define ll long long

int dp[50000+1];
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int N;
	cin>>N;
	int cnt=0;
	for(int i=0;i<=N;++i){
		dp[i]=0;
	}
	dp[1]=1;
	dp[2]=2;
	dp[3]=3;
	for(int i=4;i<=N;++i){
		dp[i]=122232421;
		for(int j=1;j*j<=i;++j){
			dp[i]=min(dp[i-j*j]+1,dp[i]);
		}
	}
	cout<<dp[N];
	return 0;
}