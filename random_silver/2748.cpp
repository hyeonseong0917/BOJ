#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

#define ll long long

ll dp[90+1];
int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		ll n;
		cin>>n;
		dp[1]=1;
		dp[2]=1;
		for(ll i=3;i<=90;++i){
			dp[i]=dp[i-1]+dp[i-2];
		}
		cout<<dp[n];

	}
	return 0;
}