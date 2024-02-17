#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
int diff[1000+1];
int dp[1000+1];

int main() {
	// your code goes here
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>diff[i];
	}
	for(int i=0;i<N;++i){
		int c=0;
		cin>>c;
		diff[i]-=c;
		dp[i]=0;
	}
	dp[0]=abs(diff[0]);
	for(int i=1;i<N;++i){
		if(diff[i]*diff[i-1]<=0){
			dp[i]=dp[i-1]+abs(diff[i]);
		}else{
			dp[i]=dp[i-1]+max(0,abs(diff[i])-abs(diff[i-1]));
		}
	}
	cout<<dp[N-1];
	
	return 0;
}