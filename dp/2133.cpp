#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

#define ll long long

const int MAX=30+1;
int dp[MAX]={0,};
int main() {
	// your code goes here
	int N;
	cin>>N;
	dp[0]=1;
	dp[1]=0;
	dp[2]=3;
	dp[4]=(dp[2]*dp[2])+2;
	for(int i=6;i<=30;++i){
		if(i%2==1) continue;
		for(int j=2;i-j>=0;j+=2){
			if(j==2){
				dp[i]+=dp[i-j]*dp[j];
			}else{
				dp[i]+=dp[i-j]*2;
			}
			
		}
	}
	cout<<dp[N];
	return 0;
}