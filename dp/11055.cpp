#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX=1000+1;
int N;
int a[MAX];
int dp[MAX];

int main() {
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>a[i];
	}
	for(int i=0;i<N;++i){
		dp[i]=a[i];
	}
	// dp[0]=a[0];
	for(int i=1;i<N;++i){
		for(int j=0;j<i;++j){
			if(a[j]<a[i]){
				dp[i]=max(dp[i],dp[j]+a[i]);
			}
		}
		// cout<<i<<" "<<dp[i]<<"\n";
	}
	int ans=-1;
	for(int i=0;i<N;++i){
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}