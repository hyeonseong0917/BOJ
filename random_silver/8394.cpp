#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
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
		vector<ll> dp(n+1,0);
		dp[0]=1;
		dp[1]=1;
		dp[2]=2;
		for(ll i=3;i<=n;++i){
			dp[i]=(dp[i-1]%10+dp[i-2]%10)%10;
		}
		cout<<dp[n];
	}
	return 0;
}