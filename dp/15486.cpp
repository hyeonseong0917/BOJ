#include <iostream>
using namespace std;

const int MAX=1500000+1;
int main() {
	// your code goes here
	int N=0;
	cin>>N;
	int T[MAX];
	int P[MAX];
	int dp[MAX];
	for(int i=0;i<MAX;++i){
		T[i]=0;
		P[i]=0;
		dp[i]=0;
	}
	for(int i=1;i<=N;++i){
		cin>>T[i]>>P[i];
	}
	int ans=-1;
	for(int i=1;i<=N+1;++i){
		ans=max(ans,dp[i]);
		if(i+T[i]<=N+1){
			dp[i+T[i]]=max(ans+P[i],dp[i+T[i]]);
		}
	}
	cout<<ans;
	return 0;
}