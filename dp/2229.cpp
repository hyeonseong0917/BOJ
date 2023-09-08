#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

const int MAX=1000+5;

int dp[MAX];
int score[MAX];
int main() {
	// your code goes here
	int N=0;
	for(int i=0;i<MAX;++i){
		dp[i]=0;
		score[i]=0;
	}
	cin>>N;
	for(int i=1;i<=N;++i){
		cin>>score[i];
	}
	dp[2]=abs(score[2]-score[1]);
	for(int i=3;i<=N;++i){
		dp[i]=dp[i-1];
		for(int j=i-1;j>=1;--j){
			dp[i]=max(dp[i],abs(score[i]-score[j])+dp[j-1]);
		}
	}
	cout<<dp[N];


	


	return 0;
}