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
		ll t;
		cin>>t;
		ll mod=1000000007;
		vector<ll> dp(5000+1,0);
		dp[0]=1;
		dp[2]=1;
		dp[4]=2;
		for(ll i=6;i<=5000;i+=2){
			for(ll j=0;j+2<=i;++j){
				dp[i]+=(dp[j]%mod)*(dp[i-j-2]%mod);
				dp[i]%=mod;
			}
		}
		while(t--){
			ll a;
			cin>>a;
			cout<<dp[a]<<"\n";
		}

		
	}
	return 0;
}