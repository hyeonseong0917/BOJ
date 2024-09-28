#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

#define ll long long

ll dp[1000000+1];
ll mod=1000000009;
int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		dp[1]=1;
		dp[2]=2;
		dp[3]=4;
		for(ll i=4;i<=1000000;++i){
			dp[i]=(dp[i-1]+dp[i-2]+dp[i-3])%mod;
		}
		ll t;
		cin>>t;
		while(t--){
			ll n;
			cin>>n;
			cout<<dp[n]<<"\n";
		}
	}
	return 0;
}