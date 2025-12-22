#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n;
		cin>>n;
		vector<ll> dp(n+1,0);
		vector<ll> psum(n+1,0);
		dp[0]=1;
		psum[0]=1;
		dp[1]=2;
		psum[1]=3;
		dp[2]=7;
		psum[2]=10;
		ll mod=1000000007;
		for(ll i=3;i<=n;++i){
			dp[i]=(dp[i-1]*2)%mod+(dp[i-2]*3)%mod+(psum[i-3]*2)%mod;
			dp[i]%=mod;
			psum[i]=psum[i-1]+dp[i];
			psum[i]%=mod;
		}
		cout<<dp[n];
	}
	return 0;
}
