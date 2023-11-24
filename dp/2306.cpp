#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

const int MAX=500+5;

int dp[MAX][MAX];
string s;
int N;
int main() {
	// your code goes here
	cin>>s;
	N=s.size();
	for(int i=0;i<MAX;++i){
		for(int j=0;j<MAX;++j){
			dp[i][j]=0;
		}
	}
	for(int i=1;i<N;++i){
		for(int j=0;j<N;++j){
			int t=i+j;
			if((s[j]=='a' && s[t]=='t') || (s[j]=='g' && s[t]=='c')){
				dp[j][t]=dp[j+1][t-1]+2;
			}
			for(int k=j;k<N;++k){
				dp[j][t]=max(dp[j][t],dp[j][k]+dp[k+1][t]);
			}
		}
	}

	cout<<dp[0][N-1];


	return 0;
}