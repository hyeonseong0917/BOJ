#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

#define ll long long

ll dp[1000000+1];

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		ll n;
		cin>>n;
		dp[0]=0;
		dp[1]=0;
		dp[2]=1;
		dp[3]=1;
		for(ll i=4;i<=n;++i){
			// dp[i]=min(dp[i-1]+1, dp[i/2]+1, dp[i/3]+1)
			ll min_num=2023101800;
			min_num=min(min_num,dp[i-1]+1);
			if(i%2==0){
				min_num=min(min_num,dp[i/2]+1);
			}
			if(i%3==0){
				min_num=min(min_num,dp[i/3]+1);
			}
			dp[i]=min_num;
		}
		
		cout<<dp[n]<<"\n";
		// dp[10]=3 dp[9]=2 dp[3]=1 dp[1]=0
		ll cnt=dp[n];
		ll last_num=n;
		cout<<n<<" ";
		--cnt;
		for(ll i=n-1;i>=1;--i){
			if(cnt==dp[i] && (i+1==last_num || i*2==last_num || i*3==last_num)){
				cout<<i<<" ";
				last_num=i;
				--cnt;
			}
		}
	}
	return 0;
}