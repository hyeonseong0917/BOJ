#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n,k;
		cin>>n>>k;
		vector<ll> dp(n+1,2023101800);
		dp[0]=0;
		for(ll i=0;i<=n;++i){
			if(i+1<=n){
				dp[i+1]=min(dp[i+1],dp[i]+1);
			}
			if(i+i/2<=n){
				dp[i+i/2]=min(dp[i+i/2],dp[i]+1);
			}
		}
		if(dp[n]<=k){
			cout<<"minigimbob";
		}else{
			cout<<"water";
		}
	}
	return 0;
}