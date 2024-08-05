#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		ll n;
		cin>>n;
		vector<ll> dp(1000+1,0);
		dp[1]=1;
		dp[2]=2;
		dp[3]=1;
		dp[4]=1;
		for(ll i=5;i<=n;++i){
			if(dp[i-1]==2 || dp[i-3]==2 || dp[i-4]==2){
				dp[i]=1;
			}else{
				dp[i]=2;
			}
		}
		if(dp[n]==1){
			cout<<"SK";
		}else{
			cout<<"CY";
		}
	}
	return 0;
}