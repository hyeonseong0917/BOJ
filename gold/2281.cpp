#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long

int dp[1000+2];
int v[1000+1];
int main() {
	// your code goes here
	int t=1;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=0;i<n;++i){
			cin>>v[i];
		}
		for(int i=0;i<1000+2;++i){
			dp[i]=0;
		}
		for(int i=n-2;i>=0;--i){
			dp[i]=(m-v[i])*(m-v[i])+dp[i+1];
			for(int j=i+1;j<n;++j){
				int cur_sum=0;
				for(int k=i;k<=j;++k){
					cur_sum+=v[k];
				}
				cur_sum+=(j-i);
				if(cur_sum<=m){
					if(j==n-1){
						dp[i]=0;
					}
					dp[i]=min(dp[i],(m-cur_sum)*(m-cur_sum)+dp[j+1]);
				}else{
					break;
				}
			}
			// cout<<i<<" "<<dp[i]<<endl;
		}
		cout<<dp[0];
	}

	return 0;
}