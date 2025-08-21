#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		// 0 1 2 3 4 5 6 7 8
		// 1 2 3 4 5 6 6 6 7
		// 3 4 5 6 7 8 8 8 9
		// dp[x]: x인덱스를 마지막으로 하는 계단의 길이
		// if(v[x+1]>dp[x]) dp[x+1]=dp[x]+1;
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		vector<ll> dp(n,1);
		for(ll i=1;i<n;++i){
			if(v[i]>dp[i-1]){
				dp[i]=dp[i-1]+1;
			}else if(v[i]==dp[i-1]){
				dp[i]=dp[i-1];
			}else{
				// v[i]<dp[i-1]
				dp[i]=min(v[i],dp[i-1]);
			}
		}
		ll ans=0;
		for(ll i=0;i<n;++i){
			ans=max(ans,dp[i]);
		}
		cout<<ans;
	}
	return 0;
}