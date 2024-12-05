#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

#define ll long long
#define pb push_back

ll dp[10001];
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	
	while(o--){
		ll t;
		cin>>t;
		// vector<ll> dp(10000+1,0);
		dp[1]=1;
		dp[2]=1;
		// for(ll i=3;i<=10000;++i){
		// 	dp[i]=dp[i-1]+dp[i-2];
		// }
		ll cnt=1;
		while(t--){
			ll p,q;
			cin>>p>>q;
			dp[1]=1;
			dp[2]=1;
			for(ll i=3;i<=p;++i){
				// dp[i]=dp[i-1]%q+dp[i-2]%q;
				dp[i]=(dp[i-1]+dp[i-2])%q;
				// dp[i]%=q;
			}
			cout<<"Case #"<<cnt<<": "<<dp[p]%q<<"\n";
			++cnt;
		}

	}
	return 0;
}