#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n;
		cin>>n;
		vector<ll> dp(n+1,0);
		for(ll i=1;i<=min(n,(ll)6);++i){
			dp[i]=i;
		}
		for(ll i=7;i<=n;++i){
			for(ll j=0;j<=i-2;++j){
				dp[i]=max(dp[i],dp[j]*(i-2+1-j));
			}
		}
		cout<<dp[n];
	}
	return 0;
}